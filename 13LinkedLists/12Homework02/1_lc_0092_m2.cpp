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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dmy = new ListNode(0);
        dmy->next = head;
        ListNode *prv = dmy;
        for (int i{0}; i<m-1; i++) prv = prv->next;
        ListNode *cur = prv->next, *nxt;
        for (int i{0}; i< n-m; i++) {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = prv->next;
            prv->next = nxt;
        }
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
