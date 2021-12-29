#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0) return;
    Node *walk = head;
    for (int i = 1; i < position; i++) walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node *head);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, num;
        cin >> n;
        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);
        for (int i = 0; i < n - 1; i++) {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        int pos;
        cin >> pos;
        loopHere(head, tail, pos);
        cout << countNodesinLoop(head) << endl;
    }
    return 0;
}

int countNodesinLoop(struct Node *head) {
    if (!head || !head->next) return 0;
    Node *slow  = head, *fast  = head, *p = head;
    bool hasCycle = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    if (!hasCycle) return 0;
    while (p != slow) {
        p = p->next;
        slow = slow->next;
    }
    int cnt{1};
    Node* tmp = p->next;
    while (tmp != p) tmp = tmp->next, cnt++;
    return cnt;
}
