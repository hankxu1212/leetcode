#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int longestValidParentheses(string s) {
    int dp[30001];
    int m = 0;
    for(int i=0;i<s.length();i++){
        dp[i] = 0;
    }
    for(int i=1;i<s.length();i++){
        if(s[i] == ')'){
            if(s[i-1] == '(')
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            else if(i - dp[i - 1] > 0 && s[i-dp[i-1]-1] == '('){
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
        }
        m = max(m,dp[i]);
    }
    return m;
}

//Util function for generateParenthesis
void gen(int l, int r, int n, vector<string> &res, string curr){
    if(l == n && r == n){
        res.push_back(curr);
    }
    //add (
    if(l < n && l >= r){
        gen(l+1,r,n,res, curr + "(");
    }
    //add )
    if(r < n && l > r){
        gen(l,r+1,n,res, curr + ")");
    }
}
vector<string> generateParenthesis(int n){
    vector<string> res;
    gen(1,0,n,res,"(");
    return res;
}

int main(){
    vector<string> v = generateParenthesis(3);
    return 0;
}