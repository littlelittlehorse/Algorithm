#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomNote_count,  magazine_count;
        for (int i = 0; i < ransomNote.size(); i++)
            ransomNote_count[ransomNote[i]]++;
        for (int i = 0; i < magazine.size(); i++)
            magazine_count[magazine[i]]++;

        for (char c = 'a'; c <= 'z'; c++) {
            if (ransomNote_count[c] > magazine_count[c])
                return false;
        }
        return true;
    }
};