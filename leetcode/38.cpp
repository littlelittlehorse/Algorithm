#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        string s = "1", ans = "1";
        for (int i = 2; i <= n; i++) {
            ans = "";
            for (int j = 0; j < int(s.size()); ) {
                int k = j;
                while(k < int(s.size()) && s[j] == s[k])
                    ++k;
                ans = ans + to_string(k - j) + s[j];
                j = k;
            }
            s = ans;
        }
        return ans;
    }
};

