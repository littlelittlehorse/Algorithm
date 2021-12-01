#include <bits/stdc++.h>

using namespace std;


struct TrieNode {
    int val;
    TrieNode *left;
    TrieNode *right;
    TrieNode() : val(0), left(nullptr), right(nullptr) {}
    TrieNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TrieNode(int x, TrieNode *left, TrieNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> num;
    int kthSmallest(TrieNode* root, int k) {
        dfs(root);
        return num[k - 1];
    }
    void dfs(TrieNode *node) {

        if (node->left != NULL)
            dfs(node->left);

        if (node->right != NULL)
            dfs(node->right)
        num.pop_back(node->val);
    }
};