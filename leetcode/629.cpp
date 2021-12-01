#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[2][1003];
    const int mod = 1000000007;
    int kInversePairs(int n, int k) {
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int now = i & 1, last = now ^ 1;
                dp[now][j] = (j - 1 >= 0 ? dp[now][j - 1] : 0) + dp[last][j] - (j - i >= 0 ? dp[last][j - i] : 0);
                if (dp[now][j] >= mod)
                    dp[now][j] -= mod;
                if (dp[now][j] < 0)
                    dp[now][j] += mod;

            }
        }
        return dp[n & 1][k];
    }
};
