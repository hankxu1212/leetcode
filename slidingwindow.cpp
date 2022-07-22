#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
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

int main(){
    cout << lengthOfLongestSubstring("abcabcbb");
    return 0;
}