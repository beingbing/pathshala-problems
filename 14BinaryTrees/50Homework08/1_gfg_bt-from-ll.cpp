#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

int main() {
    int T, i, n, l, k;
    cin >> T;
    while (T--) {
        struct Node *head = NULL;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1\n";
        lvl(root);
        cout << endl;
        getchar();
    }
    return 0;
}

void convert(Node *head, TreeNode *&root) {
    if (!head) {
        root = NULL;
        return;
    }
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    while(!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if(head->next) {
            curr->left = new TreeNode(head->next->data);
            q.push(curr->left);
            head = head->next;
        }
        if(head->next) {
            curr->right = new TreeNode(head->next->data);
            q.push(curr->right);
            head = head->next;
        }
    }
}
