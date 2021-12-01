#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    queue<char> q;
    int lengthOfLongestSubstring(string s) {
        vector<char> cnt(128, 0);
        int ans = 0;
        for (int i = 0; i < int(s.size()); i++) {
            q.push(s[i]), cnt[s[i]]++;
            while (cnt[s[i]] > 1) {
                char frontC = q.front();
                q.pop();
                cnt[frontC]--;
            }
            ans = max(ans, int(q.size()));
        }
        return ans;
    }
};


void test() {
    string s = "";
    Solution solution;
    int ans = solution.lengthOfLongestSubstring(s);
    cout << ans << endl;
}


int main() {
    test();
}
