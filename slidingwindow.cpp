#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
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
    
}

int main(){
    cout << lengthOfLongestSubstring("abcabcbb");
    return 0;
}