#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
#include<unordered_map>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int del = dp[i-1][j] + 1;
                int ins = dp[i][j-1] + 1;
                int rep = dp[i-1][j-1] + 1;
                dp[i][j] = min(del, min(ins,rep));
            }
        }
    }
    return dp[n][m];
}

int main(){
    return minDistance("horse", "ros");
}