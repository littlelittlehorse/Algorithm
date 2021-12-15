#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > graph;
    vector<int> ans;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        graph.resize(quiet.size());
        ans.resize(quiet.size(), -1);

        for (int i = 0; i < richer.size(); i++)
            graph[richer[i][1]].push_back(richer[i][0]);

        for (int i = 0; i < quiet.size(); i++) {
            if (ans[i] == -1)
                dfs(i, quiet);
        }
        return ans;
    }

    int dfs(int x, vector<int>& quiet) {
        if (ans[x] != -1)
            return ans[x];

        if (graph[x].size() == 0)
            return ans[x] = x;

        ans[x] = x;
        for (int i = 0; i < graph[x].size(); i++) {
            int id = dfs(graph[x][i], quiet);
            if (quiet[ans[x]] > quiet[id])
                ans[x] = id;
        }
        return ans[x];
    }
};