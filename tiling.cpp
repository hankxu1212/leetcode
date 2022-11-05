#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
using namespace std;

//tiling 1x2 or triangle -> 2xn
int numTilings(int n) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp (n,vector<int> (2,0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 2;
    dp[1][1] = 2;
    for(int i=2;i<n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-2][0] + 2 * dp[i-2][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }
    return dp[n-1][0];
}

// tiling 1x1x2 -> 2x2xn
int threeD_tilings(int n){
    // https://www.quora.com/In-how-many-ways-can-you-fit-1-X-1-X-2-sized-dominoes-into-a-domino-of-dimensions-2-X-2-X-N-where-N-is-a-variable
    // initial: F0 = 1, F1 = 2; I0 = 0, I1 = 0, I2 = 4;
    // complete: Fn = 2Fn-1 + Fn-2 + In
    // incomplete: In = In-1 + 4Fn-2
    // ==> Fn = 3Fn-1 + 3Fn-2 - Fn-3
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 9;
    for(int i=3;i<=n;i++){
        dp[i] = 3*dp[i-1] + 3*dp[i-2] - dp[i-3];
    }
    return dp[n];
}