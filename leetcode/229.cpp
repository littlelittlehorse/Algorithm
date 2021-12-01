#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<int> ans;
        for (auto &it: count) {
            if (it.second > n / 3)
                ans.push_back(it.first);
        }
        return ans;
    }
}


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int v1 = -1, v2 = -1, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 > 0 && nums[i] == v1) {
                cnt1++;
            } else if (cnt2 > 0 && nums[i] == v2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1++;
                v1 = nums[i];
            } else if (cnt2 == 0) {
                cnt2++;
                v2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }

        }
        int cnt_1 = 0, cnt_2 = 0;
        for (auto & num : nums) {
            if (cnt1 > 0 && num == element1) {
                cnt_1++;
            }
            if (cnt2 > 0 && num == element2) {
                cnt_2++;
            }
        }
        vector<int> ans;
        if (cnt_1 > nums.size() / 3)
            ans.push_back(v1);
        if (cnt_2 > nums.size() / 3)
            ans.push_back(v2);

        return ans;
    }
};


