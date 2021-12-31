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
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *prv = nullptr, *cur = head, *sec = head->next;
        int count{0};
        while (cur->next) {
            prv = cur;
            cur = cur->next;
            prv->next = cur->next;
            count++;
        }
        if (count % 2 != 0) prv->next = sec;
        else cur->next = sec;
        return head;
    }
};
