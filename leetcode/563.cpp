#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TrieNode *left;
    TrieNode *right;
    TrieNode() : val(0), left(nullptr), right(nullptr) {}
    TrieNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TrieNode(int x, TrieNode *left, TrieNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans;
    int dfs(TreeNode *node) {
        if (node == nullptr)
            return 0;
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        ans += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }

    int findTilt(TreeNode* root) {
        return dfs(root);
    }
};