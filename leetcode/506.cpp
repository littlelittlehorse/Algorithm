#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int> > score_index;
        string rank[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < score.size(); i++)
            score_index.push_back(make_pair(score[i], i));

        sort(score_index.begin(), score_index.end(),
             [&](const pair<int, int>& x, const pair<int, int>& y) {return x.first > y.first;});

        vector<string> ans(score.size());
        for (int i = 0; i < score_index.size(); i++) {
            if (i < 3)
                ans[score_index[i].second] = rank[i];
            else
                ans[score_index[i].second] = to_string(i + 1);
        }
        return ans;
    }
};
