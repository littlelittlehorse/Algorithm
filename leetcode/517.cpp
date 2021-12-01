#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int ans = 0, sum = 0, presum = 0;
        for (int i = 0; i < machines.size(); i++)
            sum += machines[i];

        if (sum % machines.size() != 0)
            return -1;

        int avg = sum / machines.size();

        for (int i = 0; i < machines.size(); i++) {
            presum += machines[i];
            ans = max(ans, max(machines[i] - avg, abs(presum - avg * (i + 1))));
        }
        return ans;
    }
};
