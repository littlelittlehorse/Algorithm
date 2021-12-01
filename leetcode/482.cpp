#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ss, ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-')
                continue;

            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
            ss += s[i];
        }

        int first = ss.size() % k;
        if (first != 0) {
            ans += ss.substr(0, first);
            ans += '-';
        }

        for (int i = first; i < ss.size(); i += k) {
            ans += ss.substr(i, k);
            ans += '-';
        }
        if (ans.size() > 0 && ans[ans.size() - 1] == '-') {
            ans = ans.substr(0, ans.size() - 1);
        }
        return ans;
    }
};

