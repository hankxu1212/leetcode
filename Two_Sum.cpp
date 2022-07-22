#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> m;
    vector<int> v;

    for(int i=0;i<nums.size();i++){
        if(m.find(target-nums[i]) == m.end()){
            m[nums[i]] = i;
        }
        else{
            v.push_back(i);
            v.push_back(m[target - nums[i]]);
            return v;
        }
    }
    return v;
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> r = twoSum(nums,target);
    for(int i=0;i<r.size();i++){
        std::cout << r[i] << " " << endl;
    }
    return 0;
}