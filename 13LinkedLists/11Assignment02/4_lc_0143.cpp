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

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && (fast->next) && (fast->next->next)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

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
    void reorderList(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* r = reverseList(mid->next);
        mid->next = nullptr;
        ListNode* h = head;
        ListNode *p1 = h, *p2 = r;
        while (h && r) {
            p1 = h->next;
            p2 = r->next;
            h->next = r;
            r->next = p1;
            h = p1;
            r = p2;
        }
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
    Solution obj;
    obj.reorderList(head);
    ListNode* ans = head;
    cout << "ans: ";
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
