//
// Created by ymkzpx on 2021/6/23.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> numExist;
    vector<int> twoSum(vector<int> &nums, int target) {
      vector<int> ans;
      for (int i = 0; i < nums.size(); i++) {
        int b = target - nums[i];
        if (numExist.count(b)) {
          ans.push_back(i);
          ans.push_back(numExist.at(b));
          break;
        }
        numExist[nums[i]] = i;
      }
      return ans;
    }
};

void test() {
  vector<int> a;
  for (int i = 1; i <= 4; i++) {
    a.push_back(i);
  }
  Solution solution;
  vector<int> ans = solution.twoSum(a, 6);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}


int main() {
//  test();

  assert(0);
}



