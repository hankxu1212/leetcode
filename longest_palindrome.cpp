#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

string longestPalindrome(string s) {
    bool p[1001][1001];
    //p[i][j] = s[i,i+j)
    //initialize
    for(int i=0;i<s.length();++i){
        p[i][1] = true;
    }
    for(int i=0;i<s.length()-1;++i){
        if(s[i] == s[i+1]) {
            p[i][2] = true;
        }
    }

    //dp
    for(int k=3;k<=s.length();k++){
        for(int i=0;i+k <= s.length();i++){
            if(s[i] == s[i+k-1] && p[i+1][k-2]){
                p[i][k] = true;
            }
        }
    }
    for(int k=s.length();k>=0;k--){
        for(int i=0;i<s.length();i++){
            if(p[i][k]) return s.substr(i,k);
        }
    }
    return "";
}

int main(){
    cout << longestPalindrome("cbbd");
    return 0;
}