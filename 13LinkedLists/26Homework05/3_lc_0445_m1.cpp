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

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp; 
        }
        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dmy = new ListNode(0);
        ListNode *ptr = dmy;
        stack<int> s1, s2;
        while (l1) s1.push(l1->val), l1 = l1->next;
        while (l2) s2.push(l2->val), l2 = l2->next;
        int sum = 0;
        while (!s1.empty() || !s2.empty() || sum) {
            if (!s1.empty()) sum += s1.top(), s1.pop();
            if (!s2.empty()) sum += s2.top(), s2.pop();
            ptr->next = new ListNode(sum%10);
            sum /= 10;
            ptr = ptr->next;
        }
        dmy->next = reverseList(dmy->next);
        return dmy->next;
    }
};
