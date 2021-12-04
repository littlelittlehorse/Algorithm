#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    const int mod = 1337;
    int quick_mod(int x, int y) {
        int res = 1;
        while (y) {
            if (y & 1) res = (res * x) % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;

        int last = b.back();
        b.pop_back();
        return quick_mod(a, last) % mod * quick_mod(quick_mod(a, b), 10) % mod;
    }
};