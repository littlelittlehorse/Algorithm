#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int num = digits[i] + cnt;
            digits[i] = num % 10;
            cnt = num / 10;
        }

        if (cnt) {
            vector<int> ans(digits.size() + 1, 0);
            ans[0] = 1;
            return ans;
        }
        return digits;
    }
};