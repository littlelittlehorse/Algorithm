#include <bits/stdc++.h>

using namespace std;


// 代码来源于下面链接, 根据自己偏好, 进行了修改。
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/
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
    unordered_map<int, int> index;
    TrieNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];

        // 先把根节点建立出来
        TrieNode* root = new TrieNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TrieNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        // 构造哈希映射，快速定位中序遍历的根节点
        for (int i = 0; i <= size - 1; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};



int main() {

}