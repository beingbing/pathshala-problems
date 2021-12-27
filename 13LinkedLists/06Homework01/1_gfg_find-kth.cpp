#include <iostream>
using namespace std;

int fractional_node(struct Node *head, int k);

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Node *ptr, *start = NULL, *ptr1;
        int n, i;
        cin >> n;
        for (i = 0; i < n; i++) {
            int value;
            cin >> value;
            ptr = new Node(value);
            if (start == NULL) {
                start = ptr;
                ptr1 = ptr;
            } else {
                ptr1->next = ptr;
                ptr1 = ptr1->next;
            }
        }
        ptr1->next = NULL;
        int k;
        cin >> k;
        int p = fractional_node(start, k);
        cout << p << endl;
    }
}

int fractional_node(struct Node *head, int k) {
    int n = 0;
    Node *tmp = head;
    while (tmp) {
        tmp = tmp->next;
        n++;
    }
    n = ceil((n*1.0) / k);
    tmp = head;
    while (--n) tmp = tmp->next;
    return tmp->data;
}
