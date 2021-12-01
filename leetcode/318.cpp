#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mask[1004];
    int maxProduct(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!(mask[i] & mask[j])) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};