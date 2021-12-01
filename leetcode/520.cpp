#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        for (int i = 1; i < word.size() ; i++) {
            if (isupper(word[i])) {
                if (islower(word[i - 1]))
                    return false;
                if (i != word.size() - 1 && islower(word[i + 1]))
                    return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
            return false;
        }

        for (int i = 2; i < word.size(); ++i) {
            if (islower(word[i]) != islower(word[1])) {
                return false;
            }
        }
        return true;
    }
};
