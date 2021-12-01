#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 预处理: 增加辅助字符
        string str = preSovle(s);
        int max_id = 0, max_pos = 0, ans_pos, ans_len = 0;
        vector<int> arm_len(str.size(), 0);
        for (int i = 2; i <= str.size() - 2; i++) {
            if (max_pos > i) arm_len[i] = min(max_pos - i, arm_len[2 * max_id - i]);
            else arm_len[i] = 1;
            while (str[i + arm_len[i]] == str[i - arm_len[i]]) arm_len[i]++;
            if (i + arm_len[i] > max_pos) {
                max_pos = i + arm_len[i];
                max_id = i;
            }
            if (arm_len[i] - 1 > ans_len) {
                ans_len = arm_len[i] - 1;
                ans_pos = i;
            }
        }
        int pos = (ans_pos - 2) / 2;
        return str[ans_pos] == '#' ? s.substr(pos - ans_len / 2 + 1, ans_len):
                                     s.substr(pos - ans_len / 2, ans_len);
    }
    string preSovle(string s) {
        string str = "$";
        for (int i = 0; i < s.size(); i++) {
            str += '#';
            str += s[i];
        }
        str += '#', str += '*';
        return str;
    }
};

void test() {
    Solution solution;
    string s = "abbac";
    string ans = solution.longestPalindrome(s);
    cout << ans << endl;
}

int main() {
    test();
}