//
// Created by ymkzpx on 2021/9/11.
//

#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif //LEETCODE_LIST_H
