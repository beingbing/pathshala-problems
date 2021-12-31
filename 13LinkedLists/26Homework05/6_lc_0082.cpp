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
        ListNode *dmy = new ListNode(0);
        dmy->next = head;
        ListNode *cur = dmy;
        int dup;
        while (cur->next && cur->next->next)
            if (cur->next->val == cur->next->next->val) {
                dup = cur->next->val;
                while(cur->next && cur->next->val == dup) cur->next = cur->next->next;
            } else cur = cur->next;
        return dmy->next;
    }
};
