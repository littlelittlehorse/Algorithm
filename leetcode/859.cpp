#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        unordered_map<int, int> nums, numg;
        vector<int> pos;
        int no_match = 0, equal = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                ++no_match;
                pos.push_back(i);
            }

            if (nums.count(s[i]))
                equal = 1;
            nums[s[i]]++;
        }
        if (no_match == 2 && s[pos[0]] == goal[pos[1]] && s[pos[1]] == goal[pos[0]])
            return true;

        if (no_match == 0 && equal)
            return true;

        return false;
    }
};
