#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int st = 0, ed = 0;
        for (int i = 0; i < s.size(); i++) {
            auto ans1  = expandMaxLen(s, i, i);
            auto ans2  = expandMaxLen(s, i, i + 1);
            if (ans1.second - ans1.first > ed - st) {
                ed = ans1.second;
                st = ans1.first;
            }
            if (ans2.second - ans2.first > ed - st) {
                ed = ans2.second;
                st = ans2.first;
            }
        }
        return s.substr(st, ed - st +  1);
    }
    pair<int, int>  expandMaxLen(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        pair<int, int> ans = {l + 1, r - 1};
        return ans;
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