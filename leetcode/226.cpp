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
    TrieNode* invertTree(TrieNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TrieNode *curNode) {
        if (curNode == NULL)
            return;
        TrieNode *left = curNode->left;
        TrieNode *right = curNode->right;

        curNode->left = right;
        curNode->right = left;

        dfs(left);
        dfs(right);
    }
};


