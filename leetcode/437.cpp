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
    int target, ans;
    int pathSum(TrieNode* root, int targetSum) {
        if (root == NULL)
            return 0;
        target = targetSum;
        dfs(root);
        return ans;
    }

    void dfs(TrieNode *node) {
        dfs2(node, 0);
        if (node->left != NULL) dfs(node->left);
        if (node->right != NULL) dfs(node->right);
    }

    void dfs2(TrieNode *node, int sum) {
        sum += node->val;
        if (sum == target)
            ++ans;
        if (node->left != NULL) dfs2(node->left, sum);
        if (node->right != NULL) dfs2(node->right, sum);
    }
};

class Solution {
public:
    map<int, int> mp;
    int target, ans;
    int pathSum(TrieNode* root, int targetSum) {
        target = targetSum;
        mp[0] = 1;
        dfs(root, 0);
        return ans;
    }

    void dfs(TrieNode* node, int sum) {
        if (node == NULL)
            return;
        sum += node->val;
        ans += mp[sum - target];
        if (mp.find(sum) != mp.end()) mp[sum]++;
        else mp[sum] = 1;
        dfs(node->left, sum);
        dfs(node->right, sum);
        mp[sum]--;
    }
};