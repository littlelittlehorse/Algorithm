#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int Min = 1e9;
        for (int i = 0; i < nums.size(); i++)
            Min = min(Min, nums[i]);

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += nums[i] - Min;

        return ans;
    }
};


