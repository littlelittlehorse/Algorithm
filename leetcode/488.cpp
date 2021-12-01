#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    unordered_map<char, int> mp;
    unordered_map<string, bool> vis;
    char color[5] = {'R', 'Y', 'B', 'G', 'W'};
    int ans = 100;
    int findMinStep(string board, string hand) {
        for (auto &it : hand)
            ++mp[it];

        board = eliminate(board);
        dfs(board, 0);
        return ans == 100 ? -1 : ans;
    }

    void dfs(string s, int step) {
        if (vis[s])
            return;

        vis[s] = true;
        if (step >= ans)
            return;


        if (s.size() == 0) {
            ans = min(ans, step);
            return;
        }

        for (int i = 0; i < 5; i++) {

            if (!mp[color[i]])
                continue;

            for (int j = 0; j < s.size(); j++) {
                string next = s.substr(0, j + 1) + color[i] + s.substr(j + 1);
                next = eliminate(next);
                mp[color[i]] -= 1;
                dfs(next, step + 1);
                mp[color[i]] += 1;
            }
        }
    }

    string eliminate(string s) {
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0, j = 0; i < s.size(); i = j) {
                while(s[i] == s[j])
                    ++j;
                if (j - i >= 3) {
                    s = s.substr(0, i) + s.substr(j);
                    flag = true;
                    break;
                }
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    string a = "WWRRBBWW", b = "WRBRW";
    solution.findMinStep(a, b);
}