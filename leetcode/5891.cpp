#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (n + rolls.size());
        int rolls_sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            rolls_sum += rolls[i];
        }
        vector<int> ans;
        if ((sum - rolls_sum) < 0 || (sum - rolls_sum) > 6 * n || (rolls_sum + n) > sum) {
            return ans;
        }
        sum -= rolls_sum;
        for (int i = 1; i <= n; i++) {
            int cur = min(sum - (n-i), 6);
            sum -= cur;
            ans.push_back(cur);
        }
        return ans;
    }
};