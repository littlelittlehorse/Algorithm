#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    bool vis[201][201];
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push(make_pair(heightMap[i][j], make_pair(i, j)));
                    vis[i][j] = true;
                }
            }
        }


        while (!pq.empty()) {
            int h = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = dirx[i] + x, ny = diry[i] + y;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && (!vis[nx][ny])) {
                    if (heightMap[nx][ny] < h) {
                        ans += h - heightMap[nx][ny];
                    }
                    vis[nx][ny] = 1;
                    pq.push(make_pair(max(heightMap[nx][ny], h), make_pair(nx, ny)));
                }
            }
        }
        return ans;
    }
};