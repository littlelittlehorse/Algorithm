#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candySet(candyType.begin(), candyType.end());

        if (candySet.size() >= candyType.size() / 2)
            return candyType.size() / 2;
        else
            return candySet.size();
    }
};