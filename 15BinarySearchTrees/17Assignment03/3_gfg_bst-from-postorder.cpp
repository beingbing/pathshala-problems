// instead of PSE try doing it with bounds also, just like in preorder we have a soln with bounds on leetcode
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* makeBST(int p[], int i, int j, vector<int>& PSE) {
    if (i > j) return NULL;
    Node* node = new Node(p[j]);
    node->left = makeBST(p, i, PSE[j], PSE);
    node->right = makeBST(p, PSE[j]+1, j-1, PSE);
    return node;
}

Node *constructTree(int post[], int sz) {
    vector<int> PSE(sz);
    stack<int> stk;
    stk.push(sz-1);
    for (int i{sz-2}; i >= 0; i--) {
        while (!stk.empty() && post[i] < post[stk.top()]) {
            PSE[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        PSE[stk.top()] = -1;
        stk.pop();
    }
    return makeBST(post, 0, sz-1, PSE);
}

void printInorder(Node *node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int post[n];
        for (int i = 0; i < n; i++) scanf("%d", &post[i]);
        Node *root = constructTree(post, n);
        printInorder(root);
        printf("\n");
    }
    return 0;
}
