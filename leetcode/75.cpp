#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[l], nums[i]);
                l++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[l], nums[i]);
                l++;
            }
        }

    }
};

void test() {

}

int main() {
    test();
}