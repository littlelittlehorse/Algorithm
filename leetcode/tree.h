//
// Created by ymkzpx on 2021/9/11.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H


struct TrieNode {
    int val;
    TrieNode *left;
    TrieNode *right;
    TrieNode() : val(0), left(nullptr), right(nullptr) {}
    TrieNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TrieNode(int x, TrieNode *left, TrieNode *right) : val(x), left(left), right(right) {}
};


#endif //LEETCODE_TREE_H
