#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto &it: nums)
            count[it]++;

        vector<int> ans;
        for (auto &it : count) {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (auto &it : nums)
            xorSum ^= it;

        int difPos = -1;
        for (int i = 0; i <= 31; i++) {
            if (xorSum & (1 << i))
                difPos = i;
        }

        vector<int> ans(2, 0);
        for (auto &it : q) {
            if (it & (1 << difPos)) ans[0] ^= it;
            else ans[1] ^= it;
        }
        return ans;
    }
};