#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int rl, rr;
    vector<string> ans;
    string s_;
    unordered_set<string> se;
    vector<string> removeInvalidParentheses(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                rl++;
            } else if (s[i] == ')') {
                if (rl > 0) rl--;
                else rr++;
            }
        }
        s_ = s;
        dfs("", 0, 0, 0, rl, rr);
        for (auto &it : se)
            ans.push_back(it);

        return ans;
    }

    void dfs(string str, int pos, int lnum, int rnum, int cur_rl, int cur_rr) {
        if (rnum > lnum || cur_rl < 0 || cur_rr < 0)
            return;

        if (pos == s_.size()) {
            if (cur_rl == 0 && cur_rr == 0)
                se.insert(str);
            return;
        }

        if (s_[pos] == '(') {

            dfs(str, pos + 1, lnum, rnum, cur_rl - 1, cur_rr);
            str.push_back(s_[pos]);
            dfs(str, pos + 1, lnum + 1, rnum, cur_rl, cur_rr);
            str.pop_back();
        } else if (s_[pos] == ')') {
            dfs(str, pos + 1, lnum, rnum, cur_rl, cur_rr - 1);
            str.push_back(s_[pos]);
            dfs(str, pos + 1, lnum, rnum + 1, cur_rl, cur_rr);
            str.pop_back();
        } else {
            str.push_back(s_[pos]);
            dfs(str, pos + 1, lnum, rnum, cur_rl, cur_rr);
            str.pop_back();
        }
    }
};