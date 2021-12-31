#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dmy = new ListNode(0);
        ListNode *ptr = dmy;
        int sum{0};
        while (l1 || l2 || sum) {
            if (l1) sum += l1->val, l1 = l1->next;
            if (l2) sum += l2->val, l2 = l2->next;
            ptr->next = new ListNode(sum%10);
            sum /= 10;
            ptr = ptr->next;
        }
        return dmy->next;
    }
};
