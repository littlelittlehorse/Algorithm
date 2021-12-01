//https://leetcode-cn.com/problems/divide-two-integers/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool flag = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            flag = false;
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0)  divisor = -divisor;

        int ans = 0;
        while(1) {
            int a = dividend, b = divisor, cnt = 1;
            if (a > b) break;
            while(a - b <= b) {
                cnt += cnt;
                b += b;
            }
            ans += cnt;
            dividend -= b;
        }
        return ans;
    }
};

