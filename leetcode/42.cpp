#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int leftMax[100003];
    int rightMax[100003];
    int trap(vector<int>& height) {
        for (int i = 0 ; i < height.size(); i++) {
            if (i != 0)
                leftMax[i] = max(leftMax[i - 1], height[i]);
            else
                leftMax[i] = height[i];
        }

        for (int i = height.size() - 1; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);

        int ans = 0;
        for (int i = 0; i < height.size(); i++)
            ans += min(rightMax[i], leftMax[i]) - height[i];
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> sta;
        for (int i = 0; i < height.size(); i++) {
            while(!sta.empty() && height[i] > height[sta.top()]) {
                int index = sta.top();
                sta.pop();
                if (sta.empty())
                    break;
                int leftIndex = sta.top();
                int h = min(height[i], height[leftIndex]) - height[index];
                int d = i - leftIndex - 1;
                ans += h * d;
            }
            sta.push(i);
        }
        return ans;
    }
};