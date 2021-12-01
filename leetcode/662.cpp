#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> num;
    int ans;
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 1, 1);
        return ans;
    }

    void dfs(TreeNode *node, int depth, int val) {
        if (node == nullptr)
            return;
        if (num.find(depth) == num.end())
            num[depth] = val;
        ans = max(ans, val - num[depth] + 1);
        dfs(node->left, depth + 1, val * 2);
        dfs(node->right, depth + 1, val * 2 + 1);
    }
};