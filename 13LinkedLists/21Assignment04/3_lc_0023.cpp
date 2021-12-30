#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        ListNode* head;
        ListNode* tail;
        ListNode* p1 = h1;
        ListNode* p2 = h2;
        if (h1->val <= h2->val) {
            head = h1;
            tail = h1;
            p1 = p1->next;
        } else {
            head = h2;
            tail = h2;
            p2 = p2->next;
        }
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        if (p1) tail->next = p1;
        if (p2) tail->next = p2;
        return head;
    }

    ListNode *mergek(vector<ListNode *> &lists, int i, int j) {
        if (i == j) return lists[i];
        int m = (i + j) / 2;
        ListNode *h1 = mergek(lists, i, m);
        ListNode *h2 = mergek(lists, m + 1, j);
        return mergeTwoLists(h1, h2);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        return mergek(lists, 0, lists.size() - 1);
    }
};
