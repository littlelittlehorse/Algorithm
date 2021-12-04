#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int s_length= s.size(), k_end = 0, word_count = 0;
        for (int i = 1; i <= s_length; i++) {
            if (i == s_length || s[i] == ' ')
                word_count++;
            if (word_count == k) {
                k_end = i;
                break;
            }
        }
        return s.substr(0, k_end);
    }
};