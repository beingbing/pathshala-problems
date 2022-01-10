#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n);

void printPreorder(Node *node) {
    if (node == NULL) return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int in[n], level[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> level[i];
        Node *root = NULL;
        root = buildTree(in, level, 0, n - 1, n);
        printPreorder(root);
        cout << endl;
    }
    return 0;
}

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n) {
    if (n == 0) return NULL;
    unordered_map<int, int> mp;
    Node *root = new Node(levelOrder[0]);
    for (int i = 0; i < n; i++) mp[inorder[i]] = i;
    queue<Node *> q;
    q.push(root);
    for (int i = 1; i < n; i++) {
        Node *res = new Node(levelOrder[i]);
        Node *temp = q.front();
        if (mp[temp->key] > mp[res->key]) temp->left = res;
        else {
            temp->right = res;
            q.pop();
        }
        q.push(res);
    }
    return root;
}
