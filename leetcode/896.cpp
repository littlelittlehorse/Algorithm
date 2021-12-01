#include <bits/stdc++.h>

using namespace std;

unordered_set<string> isok;

void init() {
    for (int i = 1; i <= 1e9; i *= 2) {
        int n = i;
        string cnt(10, 0);
        while (n) {
            ++cnt[n % 10];
            n /= 10;
        }
        isok.insert(cnt);
    }
}

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        return isok.count(solve(n));
    }
};