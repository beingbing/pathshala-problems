#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head, *tmp;
        if (l1->val <= l2->val) {
            head = l1;
            tmp = head->next;
            head->next = NULL;
            head->next = mergeTwoLists(tmp, l2);
        } else {
            head = l2;
            tmp = head->next;
            head->next = NULL;
            head->next = mergeTwoLists(l1, tmp);
        }
        return head;
    }
};
