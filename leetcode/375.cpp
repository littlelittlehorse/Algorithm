#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[207][207];
    int getMoneyAmount(int n) {
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = 1e9 + 7;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};