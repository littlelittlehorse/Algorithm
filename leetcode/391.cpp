#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<pair<int, int>, int> count;
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minx = rectangles[0][0], miny = rectangles[0][1], maxx = rectangles[0][2], maxy = rectangles[0][3];

        int resSum = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            resSum += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);

            minx = min(minx, rectangles[i][0]);
            miny = min(miny, rectangles[i][1]);
            maxx = min(maxx, rectangles[i][2]);
            maxy = min(maxy, rectangles[i][3]);

            count[make_pair(rectangles[i][0], rectangles[i][1])]++;
            count[make_pair(rectangles[i][0], rectangles[i][3])]++;
            count[make_pair(rectangles[i][2], rectangles[i][1])]++;
            count[make_pair(rectangles[i][2], rectangles[i][3])]++;
        }

        if (resSum != (maxx - minx) * (maxy - miny))
            return false;

        count[make_pair(minx, miny)]--;
        count[make_pair(minx, maxy)]--;
        count[make_pair(maxx, maxy)]--;
        count[make_pair(maxx, miny)]--;

        for (auto & it : count) {
            if (it != 2 && it != 4)
                return false;
        }
        return true;
    }
};