#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TrieNode() : val(0), left(nullptr), right(nullptr) {}
    TrieNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TrieNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* dfs(TreeNode* node, int val) {
        if (node == nullptr)
            return node;

        if (node->val == val)
            return node;

        if (val < node->val)
            return dfs(node->left, val);
        else
            return dfs(node->right, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val);
    }
};
