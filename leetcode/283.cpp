#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> moveNum(nums.size());
        int zerocnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zerocnt++;
            else moveNum[i] = zerocnt;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            else nums[i - moveNum[i]] = nums[i];
        }
        for (int i = int(nums.size() - 1); i >= int(nums.size() - zerocnt); i--) {
            nums[i] = 0;
        }
    }
};

int main() {

}