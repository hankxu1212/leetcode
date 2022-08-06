#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

//star and char
bool isMatch(string s, string p) {
    bool dp[21][31] = { true };
    // dp[i][j] tells us if there is a match for the first i characters of string s and the first j characters of pattern p
    
    for (int i = 0; i <= s.length(); i++) 
        for (int j = 1; j <= p.length(); j++) 
            dp[i][j] = 
                p[j-1] == '*'
                ? // if the last character was a *:
                    dp[i][j-2] // check if it is valid to skip the character before * (note: if j is negative, this correctly evaluates to true, as we skip the first character and match an empty string)
                    || i-1 >= 0 && dp[i-1][j] && (p[j-2] == s[i-1] || p[j-2] == '.') // check if str[i-1] is an occurance of the repeatable character
                : // else:
                    i-1 >= 0 && dp[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]); // string up to, but not including, s[i] and p[j] match 
                
    return dp[s.size()][p.size()]; // return if there was a match for the whole string and the whole pattern
}

//sequence star and cahr
bool isMatch(string s, string p){
    bool dp[2001][2001] = {true};

    for (int i = 0; i <= s.length(); i++) 
        for (int j = 1; j <= p.length(); j++) 
                if(p[j-1] == '*'){
                    // if the last character was a *:
                    dp[i][j] = false;
                    for(int k=0;k<=i;k++){
                        //if any previous i match the segment
                        if(dp[k][j-1]) dp[i][j] = true;
                    }
                }
                else
                    dp[i][j] = i >= 1 && dp[i-1][j-1] && (p[j-1] == '?' || p[j-1] == s[i-1]); // string up to, but not including, s[i] and p[j] match 
    return dp[s.length()][p.length()];
}

int main(){
    cout << isMatch("aa","a*");
}