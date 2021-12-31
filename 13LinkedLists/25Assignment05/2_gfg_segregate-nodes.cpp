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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution {
public:
    Node *divide(int n, Node *head) {
        Node *even = NULL, *odd = NULL, *evenend = NULL, *oddend = NULL;
        Node *cur = head;
        while (cur) {
            if (cur->data % 2 == 0) {
                if (even == NULL) {
                    even = cur;
                    evenend = cur;
                } else {
                    evenend->next = cur;
                    evenend = evenend->next;
                }
            } else {
                if (odd == NULL) {
                    odd = cur;
                    oddend = cur;
                } else {
                    oddend->next = cur;
                    oddend = oddend->next;
                }
            }
            cur = cur->next;
        }
        if (even == NULL) return odd;
        if (odd == NULL) return even;
        oddend->next = NULL;
        evenend->next = odd;
        return even;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
