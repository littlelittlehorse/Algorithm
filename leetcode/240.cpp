#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            else if (target > matrix[i][j]) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            int pos = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if (pos < matrix[i].size() && matrix[i][pos] == target)
                return true;
        }
        return false;
    }
};