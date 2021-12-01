#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0, bit = 0;
        for (int i = 0; i < 20; i++) {
            int x = (a >> i) & 1, y = (b >> i) & 1;
            if (x == 1 && y == 1) {
                ans |= (bit << i);
                bit = 1;
            } else if (x | y) {
                ans |= (1 ^ bit) << i;
            } else {
                ans |= (bit << i);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int ans = solution.getSum(3, 4);
}