#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0, now_end = 0;
        for (auto &it : timeSeries) {
            int cur_end = it + duration - 1;
            if (it >= now_end)
                sum += duration;
            else
                sum += cur_end - now_end + 1;
            now = cur_end + 1;
        }
        return sum;
    }
};