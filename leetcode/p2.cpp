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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* head = new ListNode();
        ListNode* currentPos = head;
        int v = 0;
        while(l1 || l2 || v) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int res = (v + v1 + v2) / 10;
            v = (v1 + v2 + v) % 10;
            currentPos->val = v;
            v = res;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            if (l1 || l2 || v) {
                currentPos->next = new ListNode();
                currentPos = currentPos->next;
            }
        }
        return head;
    }
};

void test() {
    ListNode *l12 = new ListNode(1);
    ListNode *l11 = new ListNode(1, l12);
    ListNode *l21 = new ListNode(1);
    Solution solution;
    ListNode* head = solution.addTwoNumbers(l11, l21);
    while(head) {
        cout << head->val << ' ';
        head = head->next;
    }
}


int main() {
    test();
}
