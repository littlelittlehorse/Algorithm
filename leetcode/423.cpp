#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> s_cnt;
        for (int i = 0; i < s.size(); i++)
            s_cnt[s[i]]++;

        vector<int> ans_cnt(10, 0);
        ans_cnt[0] = s_cnt['z'];
        ans_cnt[2] = s_cnt['w'];
        ans_cnt[4] = s_cnt['u'];
        ans_cnt[6] = s_cnt['x'];
        ans_cnt[8] = s_cnt['g'];

        ans_cnt[1] = s_cnt['o'] - ans_cnt[0] - ans_cnt[2] - ans_cnt[4];
        ans_cnt[3] = s_cnt['h'] - ans_cnt[8];
        ans_cnt[5] = s_cnt['f'] - ans_cnt[4];
        ans_cnt[7] = s_cnt['s'] - ans_cnt[6];
        ans_cnt[9] = s_cnt['i'] - ans_cnt[5] - ans_cnt[6] - ans_cnt[8];

        string ans;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < ans_cnt[i]; j++)
                ans += char(i + '0');
        }
        return ans;
    }
};
