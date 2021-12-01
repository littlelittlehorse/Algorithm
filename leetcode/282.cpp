#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> ans;
    int n, target_;
    string num_;
    vector<string> addOperators(string num, int target) {
        num_ = num;
        target_ = target;
        n = num.size();
        dfs(0, 0, 0, "");
        return ans;
    }

    void dfs(int d, long long pre, long long sum, string s) {
        if (d == n) {
            if (sum == target_)
                ans.push_back(s);
            return;
        }
        long long val = 0;
        for (int i = d; i < n; i++) {
            if (i != d && num_[d] == '0')
                break;

            val = val * 10 + num_[i] - '0';
            if (d == 0)
                dfs(i + 1, val, val, to_string(val));
            else {
                dfs(i + 1, pre  * val, sum - pre + pre * val, s + "*" + to_string(val));
                dfs(i + 1, val, sum + val, s + "+" + to_string(val));
                dfs(i + 1, -val, sum - val, s + "-" + to_string(val));
            }

        }
    }
};