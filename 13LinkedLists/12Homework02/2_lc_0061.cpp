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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !(head->next) || k == 0) return head;
        int sz = 1;
        ListNode* cur = head;
        while (cur->next) {
            sz++;
            cur = cur->next;
        }
        k %= sz;
        sz -= k;
        cur->next = head;
        while (sz--) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
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
    cin >> x;
    Solution obj;
    ListNode* ans = obj.rotateRight(head, x);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
