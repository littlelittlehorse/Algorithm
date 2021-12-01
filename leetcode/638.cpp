#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> needs_;
    vector<int> price_;
    vector<vector<int> > special_;
    int n;
    map<vector<int>, int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        price_ = price;
        special_ = special;
        n = needs.size();
        return dfs(needs);
    }
    int dfs(vector<int> needs) {
        if (dp.count(needs) != 0)
            return dp[needs];

        int Min = 0;
        for (int i = 0; i < needs.size(); i++)
            Min += needs[i] * price_[i];

        for (int i = 0; i < special_.size(); i++) {
            vector<int> nextNeeds = needs;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (special_[i][j] > nextNeeds[j])
                    flag = false;
                nextNeeds[j] -= special_[i][j];
            }
            if (!flag)
                continue;
            Min = min(Min, dfs(nextNeeds) + special_[i][n]);
        }
        return dp[needs] = Min;
    }
};

int main() {
    Solution solution;
    solution
}
