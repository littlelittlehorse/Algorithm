#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return {};

        vector<int> count_s(26, 0), count_p(26, 0);
        for (int i = 0; i < p.size(); i++) {
            count_s[s[i] - 'a']++;
            count_p[p[i] - 'a']++;
        }

        vector<int> ans;
        if (count_s == count_p)
            ans.push_back(0);

        for (int i = 0; i < s.size() - p.size(); i++) {
            count_s[s[i] - 'a']--;
            count_s[s[i + p.size()] - 'a']++;

            if (count_s == count_p)
                ans.push_back(i + 1);

        }
        return ans;
    }
};