#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[105][105];
    vector<int> nums_;
    int getMaxValue(vector<int> &nums) {
        nums_ = nums;
        memset(dp, -1, sizeof(dp));
        return dfs(0, nums.size() - 1, true);
    }
    int dfs(int l, int r, bool flag) {
        if (dp[l][r] != -1)
            return dp[l][r];

        if (l == r) {
            if (flag)
                return dp[l][r] = nums_[l];
            else
                return dp[l][r] = 0;
        }

        if (flag)
            return dp[l][r] = max(dfs(l + 1, r, !flag) + nums_[l], dfs(l, r - 1, !flag) + nums_[r]);
        else
            return dp[l][r] = min(dfs(l + 1, r, !flag), dfs(l, r - 1, !flag));
    }
};


int main() {
    vector<int> a = {4,7,2,9,5,2};
    Solution solution;
    cout << solution.getMaxValue(a) << endl;
}