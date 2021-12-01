#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> num;
        int ans = 0;
        for (auto &it : nums) {
            num[it]++;
            if (num.count(it - 1)) ans = max(ans, num[it] + num[it - 1]);
            if (num.count(it + 1)) ans = max(ans, num[it] + num[it + 1]);
        }
        return ans;
    }
};