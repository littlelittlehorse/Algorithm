#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans[10004];
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                ans[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()) {
            ans[st.top()] = -1;
            st.pop();
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(ans[nums1[i]]);
        }
        return res;
    }
};
