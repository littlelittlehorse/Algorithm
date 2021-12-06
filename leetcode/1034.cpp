#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    const int dirX[4] = {0, 0, 1, -1};
    const int dirY[4] = {1, -1, 0, 0};
    int vis[53][53];
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int> > q;
        q.push(make_pair(row, col));
        vis[row][col] = 1;
        vector<pair<int, int> > ans;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            bool is_border = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + dirX[i], ny = y + dirY[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && (!vis[nx][ny]) && grid[nx][ny] == grid[row][col]) {
                    q.push(make_pair(nx, ny));
                    vis[nx][ny] = 1;
                }
                if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == grid[row][col]))
                    is_border = true;
            }
            if (is_border)
                ans.push_back(make_pair(x, y));
        }
        for (auto &it : ans) {
            grid[it.first][it.second] = color;
        }
        return grid;
    }
};