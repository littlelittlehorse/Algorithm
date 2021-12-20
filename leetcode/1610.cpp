#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int px = location[0], py = location[1], same = 0, maxx = 0;
        vector<double> d;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            if (px == x && py == y)
                same++;
            else
                d.emplace_back(atan2(py - y, px - x));
        }
        sort(d.begin(), d.end());
        int sz = d.size();
        for (int i = 0; i < sz; i++)
            d.push_back(d[i] + 2 * M_PI);

        double angleDegree = angle * M_PI / 180;
        int l = 0, r = 0;
        for (int l = 0; l < sz; ++l) {
            while (r + 1 < 2 * sz && d[r + 1] - d[l] <= angleDegree)
                r++;
            maxx = max(maxx, r - l + 1);
        }
        return same + maxx;
    }
};