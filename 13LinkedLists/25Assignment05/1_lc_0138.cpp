#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* tmp = NULL;
        Node* cur = head;
        while (cur) {
            tmp = new Node(cur->val);
            if (cur == head) cloneHead = tmp;
            Node* t = cur->next;
            cur->next = tmp;
            tmp->next = t;
            cur = t;
        }
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            else cur->next->random = NULL;
            cur = cur->next->next;
        }
        cur = cloneHead;
        Node* cur1 = head;
        while (cur && cur->next) {
            Node* t = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            cur1->next = t;
            cur1 = cur1->next;
        }
        if (cur1) cur1->next = NULL;
        return cloneHead;
    }
};
