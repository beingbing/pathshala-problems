#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size) {
    if (size == 0) return NULL;
    int val;
    cin >> val;
    Node *head = new Node(val);
    Node *tail = head;
    for (int i = 0; i < size - 1; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

int main() {
    int T, n1, n2, n3;
    cin >> T;
    while (T--) {
        cin >> n1 >> n2 >> n3;
        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);
        Node *temp = head1;
        while (temp != NULL && temp->next != NULL) temp = temp->next;
        if (temp != NULL) temp->next = common;
        temp = head2;
        while (temp != NULL && temp->next != NULL) temp = temp->next;
        if (temp != NULL) temp->next = common;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int intersectPoint(Node *head1, Node *head2) {
    Node* tmp = head1;
    while (tmp->next) tmp = tmp->next;
    tmp->next = head1;
    Node *slow  = head2, *fast  = head2, *p = head2;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    while (p != slow) {
        p = p->next;
        slow = slow->next;
    }
    return p->data;
}
