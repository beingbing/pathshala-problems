// linked list growth is used as a stack
#include <iostream>
#include <stack>
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
        int n1 = 0, n2 = 0;
        ListNode *curr1 = l1, *curr2 = l2;
        while (curr1) ++n1, curr1 = curr1->next;
        while (curr2) ++n2, curr2 = curr2->next;
        curr1 = l1, curr2 = l2;
        ListNode *stkHead = nullptr;
        while (n1 > 0 && n2 > 0) {
            int val = 0;
            if (n1 >= n2) {
                val += curr1->val; 
                curr1 = curr1->next; 
                --n1;    
            }
            if (n1 < n2) {
                val += curr2->val; 
                curr2 = curr2->next;
                --n2;    
            }
            ListNode *curr = new ListNode(val);
            curr->next = stkHead;
            stkHead = curr;    
        }
        curr1 = stkHead;
        stkHead = nullptr;
        int sum = 0;
        while (curr1) {
            sum += curr1->val;
            ListNode *curr = new ListNode(sum%10);
            curr->next = stkHead;
            stkHead = curr;
            sum /= 10;
            curr1 = curr1->next;    
        }
        if (sum != 0) {
            ListNode* curr = new ListNode(sum);
            curr->next = stkHead;
            stkHead = curr;    
        }
        return stkHead;
    }
};
