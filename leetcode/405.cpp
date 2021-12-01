#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string hex = "0123456789abcdef";
    string toHex(int num) {
        if (num == 0)
            return "0";

        long long n = num < 0 ? (long long)num + (1ll << 32) : num;

        string s;
        while (n) {
            int mod = n % 16;
            n /= 16;
            s += hex[mod];
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
