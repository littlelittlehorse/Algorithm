#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<long long, int> dp;
    int dfs(long long x) {
        if (x == 1)
            return 0;

        if (dp.count(x))
            return dp[x];

        int ans = 0;
        if (x & 1)
            ans = min(dfs(x + 1), dfs(x - 1)) + 1;
        else
            ans =  dfs(x / 2) + 1;
        return dp[x] = ans;
    }
    int integerReplacement(int n) {
        return dfs(n);
    }
};