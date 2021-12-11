#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> l_count;
        for (auto &it: licensePlate)
            if (isalpha(it))
                l_count[tolower(it)]++;

        int min_need = licensePlate.size() + 1;
        string ans;
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> w_count;
            for (auto &it: words[i])
                if (isalpha(it))
                    w_count[tolower(it)]++;

            int cur_need = 0;
            for (auto &it : l_count)
                cur_need += max(0, it.second - w_count[it.first]);

            if (cur_need == min_need && ans.size() > words[i].size())
                ans = words[i];
            if (cur_need < min_need)
                min_need = cur_need, ans = words[i];

        }
        return ans;
    }
};