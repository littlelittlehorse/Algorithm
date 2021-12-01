#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, int> secretMp, guessMp;
        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                ++bulls;
            else {
                secretMp[secret[i] - '0']++;
                guessMp[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++)
            cows += min(secretMp[i], guessMp[i]);

        string ans  = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};