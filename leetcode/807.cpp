#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rowMax[51], colMax[51];
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                ans += max(rowMax[i], col[j]) - grid[i][j];
        return ans;
    }
};