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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* bhind = head;
        ListNode* ahead = head;
        int c{0};
        while (c++ < n) ahead = ahead->next;
        if (!ahead) {
            ListNode* tmp = head->next;
            delete(head);
            return tmp;
        }
        while (ahead->next) {
            bhind = bhind->next;
            ahead = ahead->next;
        }
        ListNode* tmp = bhind->next;
        bhind->next = bhind->next->next;
        delete(tmp);
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
    ListNode* ans = obj.removeNthFromEnd(head, 2);
    while (ans) {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
