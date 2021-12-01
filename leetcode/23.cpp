#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *cur = &head;
        ListNode* left = a, *right = b;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
        }
        if (left != nullptr)
            cur->next = left;
        if (right != nullptr)
            cur->next = right;
        return head.next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;

        ListNode* left = merge(lists, l, mid);
        ListNode* right = merge(lists, mid + 1, r);

        return merge2Lists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

int main() {
    ListNode* c = new ListNode(3);
    ListNode* b = new ListNode(1, c);
    ListNode* a = new ListNode(2, b);
    ListNode* cc = new ListNode(3);
    ListNode* bb = new ListNode(1, cc);
    ListNode* aa = new ListNode(2, bb);
    vector<ListNode*> lists;
    lists.push_back(a);
    lists.push_back(aa);
    Solution solution;
    solution.mergeKLists(lists);
}