#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                ans = i;
        }
        return ans;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() == 3)
            return 1;

        int l = 1, r = arr.size() - 2;
        while(l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
                l = mid + 1;
            if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
                r = mid - 1;
        }
        return l;
    }
};


