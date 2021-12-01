#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string charType = "12210111011122000010020202";
        vector<string> ans;
        for (int i = 0; i < int(words.size()); i++) {
            string s = words[i];
            int curType = charType[tolower(s[0]) - 'a'];
            ans.push_back(s);
            for (int j = 0; j < s.size(); j++) {
                if (charType[tolower(s[j]) - 'a'] != curType) {
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};