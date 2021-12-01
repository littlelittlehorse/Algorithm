#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> count;
        for (int i = 0; i <= int(s.size()) - 10; i++) {
            string str = s.substr(i, 10);
            count[str]++;
        }
        for (auto &it : count) {
            if (it.second >= 2)
                ans.push_back(it.first);
        }
        return ans;
    }
};