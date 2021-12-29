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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dmy = new ListNode(0);
        dmy->next = head;
        ListNode *frst = dmy, *last = dmy;
        for(int jmp = 0; jmp < m-1; jmp++) frst = frst->next;
        for(int jmp = 0; jmp < n; jmp++) last = last->next;
        ListNode* tmp = last;
        last = last->next;
        tmp->next = nullptr;
        ListNode* r = reverseList(frst->next);
        frst->next->next = last;
        frst->next = r;
        return dmy->next;
    }
};

int main() {
    int n, x;
    cin >> n;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* tmp;
    while(n--) {
        cin >> x;
        ListNode* tmp = new ListNode(x);
        if (!head) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    cin >> x >> n;
    Solution obj;
    ListNode* ans = obj.reverseBetween(head, x, n);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
