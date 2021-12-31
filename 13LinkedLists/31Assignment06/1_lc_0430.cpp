class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int _val,Node* _prev,Node* _next,Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node *flatten(Node *head) {
        if (!head) return head;
        Node *pseudoHead = new Node(0, nullptr, head, nullptr);
        flattenDFS(pseudoHead, head);
        pseudoHead->next->prev = nullptr;
        return pseudoHead->next;
    }
    Node* flattenDFS(Node* prev, Node* curr) {
        if (!curr) return prev;
        curr->prev = prev;
        prev->next = curr;
        Node* tempNext = curr->next;
        Node* tail = flattenDFS(curr, curr->child);
        curr->child = nullptr;
        return flattenDFS(tail, tempNext);
    }
};
