#include <iostream>
#include <cstdio>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode(int x) {
        data = x;
        next = NULL;
    }
};

ListNode *getTail(ListNode *cur) {
    while (cur && cur->next) cur = cur->next;
    return cur;
}

ListNode *partition(ListNode *head, ListNode *end, ListNode **newHead, ListNode **newEnd) {
    ListNode *pivot = end;
    ListNode *prev = NULL, *cur = head, *tail = pivot;
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            ListNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL) (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

ListNode *quickSortRecur(ListNode *head, ListNode *end) {
    if (!head || head == end) return head;
    ListNode *newHead = NULL, *newEnd = NULL;
    ListNode *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        ListNode *tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(ListNode **headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
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
        quickSort(&head);
        while (head) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    return 0;
}
