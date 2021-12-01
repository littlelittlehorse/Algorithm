#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int> > fra_arr;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                fra_arr.push_back(make_pair(arr[i], arr[j]));
            }
        }
        sort(fra_arr.begin(), fra_arr.end(),
             [&](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first * y.second < x.second * y.first;
        });
        return {fra_arr[k - 1].first, fra_arr[k - 1].second};
    }
};