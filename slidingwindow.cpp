#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> chars(128);
    int l = 0;
    int r = 0;
    int res = 0;
    
    while(r < s.length()){
        chars[s[r]]++;
        while(chars[s[r]] > 1){
            chars[s[l]]--;
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

//Given a string s that represents a DNA sequence
//return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string,int> mp;
    vector<string> res;
    //init
    if(s.length() < 10) return res;
    
    //it
    for(int i=0; i + 10 <= s.length(); i++){
        mp[s.substr(i,10)]++;
    }
    for(auto &p : mp){
        if(p.second > 1){
            res.push_back(p.first);
        }
    }
    return res;
}

//Given an array of positive integers nums and a positive integer target,
//return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] 
//of which the sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
    int j = 0, i = 0, sum = 0, min_l = INT_MAX;
    while(j < nums.size()){
        sum += nums[j];
        while(sum >= target){
            min_l = min(min_l, j-i+1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return min_l == INT_MAX ? 0 : min_l;
}

//given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
//You can only see the k numbers in the window. Each time the sliding window moves right by one position.
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> q;
    for(int i=0;i<nums.size();i++){
        if(!q.empty() && q.front() == i - k){
            q.pop_front();
        }
        while(!q.empty() && nums[i] > nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        if(i >= k - 1){
            res.push_back(nums[q.front()]);
        }
    }
    return res;
}

int main(){
    vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
    maxSlidingWindow(nums, 5);
    return 0;
}