#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *frst = list1, *last = list1;
        for(int jmp = 0; jmp < a-1; jmp++) frst = frst->next;
        for(int jmp = 0; jmp <= b; jmp++) last = last->next;
        frst->next = list2;
        while (list2->next) list2 = list2->next;
        list2->next = last;
        return list1;
    }
};

int main() {
    int l1sz, l2sz, x;
    cin >> l1sz;
    ListNode* list1 = NULL;
    ListNode* tail = NULL;
    ListNode* tmp;
    while(l1sz--) {
        cin >> x;
        ListNode* tmp = new ListNode(x);
        if (!list1) {
            list1 = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    int a, b;
    cin >> a >> b;
    cin >> l2sz;
    ListNode* list2 = NULL;
    while (l2sz--) {
        cin >> x;
        ListNode* tmp = new ListNode(x);
        if (!list2) {
            list2 = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    Solution obj;
    ListNode* ans = obj.mergeInBetween(list1, a, b, list2);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
