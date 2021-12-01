#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int> > q;
        int pos = 0;
        for (auto &it : tickets) {
            q.push(make_pair(pos, it));
            ++pos;
        }
        int ans = 0;
        while (!q.empty()) {
            int id = q.front().first, num = q.front().second;
            ++ans;
            --num;
            if (id == k && num == 0)
                return ans;

            if (num)
                q.push(make_pair(id, num));
        }

        return ans[k];
    }
};


int m