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

struct Node *buildList(int size) {
    int val;
    cin >> val;
    Node *stkHead = new Node(val);
    Node *tail = stkHead;
    for (int i = 0; i < size - 1; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return stkHead;
}

void printList(Node *n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

long long sumDigit(Node *stkHead) {
    long long s = 0;
    while(stkHead) {
        s += + stkHead->data;
        s *= 10;
        stkHead = stkHead->next;
    }
    return s;
}

int calLen(Node *stkHead) {
    int s = 0;
    while(stkHead) s++, stkHead = stkHead->next;
    return s;
}

Node *skipLeadingZero(Node *stkHead) {
    while(stkHead && stkHead->data == 0) {
        stkHead = stkHead->next;
    }
    return stkHead;
}

Node* reverseList(Node* head) {
    Node* cur = head;
    Node* prev = NULL;
    Node* tmp;
    while (cur) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp; 
    }
    return prev;
}

Node *subLinkedList(Node *l1, Node *l2) {
    l1 = skipLeadingZero(l1);
    l2 = skipLeadingZero(l2);
    int l1len = calLen(l1);
    int l2len = calLen(l2);
    if (l1len < l2len) return subLinkedList(l2,l1);
    else if (l1len == l2len && sumDigit(l1) < sumDigit(l2)) return subLinkedList(l2,l1);

    Node *cur1 = l1, *cur2 = l2;
    Node* stkHead = nullptr;
    int borrow = 0;
    if (l1len == 0) return l2;
    if (l2len == 0) return l1;
    while (l1len > 0 && l2len > 0) {
        // cout << "l1len: " << l1len << " l2len: " << l2len << endl;
        int val = borrow * 10 + 0;
        if (l1len >= l2len) {
            val += cur1->data; 
            cur1 = cur1->next; 
            --l1len;    
        }
        if (l1len < l2len) {
            val -= cur2->data; 
            cur2 = cur2->next;
            --l2len;    
        }
        if (val < 0) val += 10, borrow++;
        // cout << "val: " << val << endl;
        Node *cur = new Node(val);
        cur->next = stkHead;
        // cout << "borrow: " << borrow << endl;
        Node* tmp = stkHead;
        while (borrow > 0) {
            (tmp->data)--;
            borrow--;
            if ((tmp->data) < 0) {
                (tmp->data) += 10;
                borrow++;
                tmp = tmp->next;
            }
        }
        stkHead = cur;
    }
    Node* head = reverseList(stkHead);
    head = skipLeadingZero(head);
    return head ? head : new Node(0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        Node *first = buildList(n);
        cin >> m;
        Node *second = buildList(m);
        Node *res = subLinkedList(first, second);
        printList(res);
    }
    return 0;
}
