#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int abs_min = 100, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            abs_min = min(abs(nums[i], abs_min));
            sum += nums[i];
        }
        sort(nums.begin(), num.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0)
                break;
            --k;
            sum += 2 * abs(nums[i]);
        }

        if (k > 0 && (k & 1))
            sum -= abs_min;

        return sum;
    }
};

int main() {

}