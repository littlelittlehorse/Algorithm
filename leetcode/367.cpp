#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long i = 1; ; i++) {
            if (i * i > num)
                break;
            if (i * i == num)
                return true;
        }
        return false;
    }
};