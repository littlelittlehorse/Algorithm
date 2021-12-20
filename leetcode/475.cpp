#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0; i < houses.size(); i++) {
            int up_pos = upper_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            int cur_min = 1e9;
            if (up_pos != heaters.size())
                cur_min = min(cur_min, heaters[up_pos] - houses[i]);
            if (up_pos - 1 >= 0)
                cur_min = min(cur_min, houses[i] - heaters[up_pos - 1]);
            ans = max(ans, cur_min);
        }
        return ans;
    }
};