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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* cur = head;
        while (cur && cnt < k) {
            cnt++;
            cur = cur->next;
        }
        if (cnt < k) return head;
        cur = head;
        ListNode* prv = NULL;
        ListNode* tmp;
        cnt = 0;
        while (cnt < k) {
            tmp = cur->next;
            cur->next = prv;
            prv = cur;
            cur = tmp;
            cnt++;
        }
        head->next = reverseKGroup(cur, k);
        return prv;
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
    cin >> x;
    Solution obj;
    ListNode* ans = obj.reverseKGroup(head, x);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
