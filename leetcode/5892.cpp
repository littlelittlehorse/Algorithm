#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count[3] = {0, 0, 0};
    bool stoneGameIX(vector<int>& stones) {

        for (int i = 0; i < stones.size(); i++) {
            count[stones[i] % 3]++;
        }

        int res = min(count[1], count[2]);
        count[1] -= res, count[2] -= res;

        int num = count[1] + count[2];

        count[0] %= 2;

        if (num & 1) {
            if (count[0] & 1)
                return false;
            else
                return true;
        } else {
            if (count[0] & 1)
                return true;
            else
                return false;
        }
    }
};

int main() {
    Solution solution;
    vector<int> a = {2};
    bool flag = solution.stoneGameIX(a);
    cout << flag << endl;
}