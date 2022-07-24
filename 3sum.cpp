#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
	sort(nums.begin(),nums.end());
	vector<vector<int>> res;

	for(int i = 0; i < nums.size(); i++){
		int j = i + 1;
		int k = nums.size() - 1;
		if(i == 0 || nums[i] != nums[i-1]){
			while(k > j){
				int sum = nums[i] + nums[j] + nums[k];
				if(sum == 0){
					res.push_back({nums[i],nums[j],nums[k]});
					k--;
					while(k >= 0 && (k == nums.size() - 1 || nums[k] == nums[k+1]))
						k--;
					continue;
				}
				else sum > 0
					? k--
					: j++
				;
			}
		}
	}
	return res;
}

int main(){
	vector<int> vec = {0,0,0};
	vector<vector<int>> v = threeSum(vec);
	for(auto &i:v){
		for(auto &j : i){
			cout << j << " ";
		}
		cout << '\n';
	}
	return 0;
}
