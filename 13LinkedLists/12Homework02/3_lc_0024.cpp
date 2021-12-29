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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* cur = head;
        ListNode* prv = head;
        ListNode* nxt;
        head = head->next;
        while(cur && cur->next) {
            prv->next = cur->next;      // first bond
            nxt = cur->next;            // second bond
            cur->next = nxt->next;      // second bond
            nxt->next = cur;            // third bond
            prv = cur;                  // setup for next swap
            cur = cur->next;            // setup for next swap
        }
        return head;
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
    ListNode* ans = obj.swapPairs(head);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
