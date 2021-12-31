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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *nxt = head->next;
        ListNode *cur = head;
        while (nxt) {
            if (cur->val == nxt->val) {
                cur->next = nxt->next;
                nxt = nxt->next;
            } else {
                cur = cur->next;
                nxt = nxt->next;
            }
        }
        return head;
    }
};
