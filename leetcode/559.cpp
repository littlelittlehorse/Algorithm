#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int dfs(Node* node) {
        if (node == nullptr)
            return 0;

        int ans = 1;
        for (int i = 0; i < node->children.size(); i++)
            ans = max(ans, dfs(node->children[i]) + 1);
        return ans;
    }
    int maxDepth(Node* root) {
        return dfs(root);
    }
};
