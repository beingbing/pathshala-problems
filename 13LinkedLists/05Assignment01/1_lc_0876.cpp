#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int x) {
        this->data = x;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && (fast->next)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    cout << obj.middleNode(head)->data << endl;
    return 0;
}
