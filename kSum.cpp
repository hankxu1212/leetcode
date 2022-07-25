#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

//REQUIRES: nums is sorted
vector<vector<int>> twoSum(vector<int> &nums, int target, int start){
	int i = start;
	int j = nums.size() - 1;
	vector<vector<int>> res;
	while(i < j){
		if(target - nums[i] < nums[i]) break;
		if(i != 0 && nums[i] == nums[i-1]){
			i++;
			continue;
		}
		
		int sum = nums[i] + nums[j];
		if(sum == target){
			res.push_back({nums[i], nums[j]});
			i++;
			j--;
		}
		else sum < target
				? i++
				: j--
		;
		while(nums[j] == nums[j+1]) j--;
	}
	return res;
}

//REQUIRES: nums is sorted
vector<vector<int>> kSum(vector<int> &nums, int start, int target, int k){
	vector<vector<int>> res;
	if(k == 2) return twoSum(nums, target, start);

	long long ave = target / k;
	if(nums[start] > ave || nums.back() < ave) return res;

	for(int i = start; i < nums.size(); ++i){
		if(i == start || nums[i-1] != nums[i]){
			for(auto &v : kSum(nums, i+1, target-nums[i], k-1)){
				v.push_back(nums[i]);
				res.push_back(v);
			}
		}
	}
	return res;
}

vector<vector<int>> fourSum(vector<int> &nums, int target){
	sort(nums.begin(),nums.end());
	vector<vector<int>> v;
	return kSum(nums, 0, target, 4);
}


