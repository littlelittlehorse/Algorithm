#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (auto &it : s)
            it = tolower(it);
        return s;
    }
};