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
    ListNode* ans = obj.reverseList(head);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
