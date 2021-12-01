#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        for (auto &it : arr) {
            dp[it] = dp[it - difference] + 1;
            ans = max(ans, dp[it]);
        }
        return ans;
    }
};