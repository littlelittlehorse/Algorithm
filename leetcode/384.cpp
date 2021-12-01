#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nums_;
    vector<int> original;

    Solution(vector<int>& nums) {
        nums_ = original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> shuffle = original;
        for (int i = 0; i < nums_.size(); i++) {
            int choosePos = rand() % shuffle.size();
            auto it = shuffle.begin();
            advance(it, choosePos);
            nums_[i] = *it;
            shuffle.erase(it);
        }
        return nums_;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */