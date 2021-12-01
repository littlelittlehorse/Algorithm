#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int r, c;
    unordered_map<int, int> point_map;
    int total_point;
    Solution(int m, int n) {
        r = m, c = n;
        total_point = m * n;
    }

    vector<int> flip() {
        int choose_point = rand() % total_point;
        total_point--;

        vector<int> ans;

        if (point_map.count(choose_point))
            ans = {point_map[choose_point] / c, point_map[choose_point] % c};
        else
            ans = {choose_point / c, choose_point % c};

        if (point_map.count(total_point))
            point_map[choose_point] = point_map[total_point];
        else
            point_map[choose_point] = total_point;

        return ans;
    }

    void reset() {
        total_point = r * c;
        point_map.clear();
    }
};