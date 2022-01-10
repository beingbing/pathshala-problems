#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int> &v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node *root) {
    vector<int> v;
    queue<Node *> q;
    q.push(root);
    Node *next_row = NULL;
    while (!q.empty()) {
        Node *n = q.front();
        q.pop();
        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }
        v.push_back(n->data);
        if (n->left) {
            q.push(n->left);
            if (next_row == NULL) next_row = n->left;
        }
        if (n->right) {
            q.push(n->right);
            if (next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

class Solution {
public:
    Node *createTree(int parent[], int n) {
        if (n == 0) return nullptr;
        vector<Node*> treeVec;
        Node* root;
        for (int i{0}; i<n; i++) treeVec.push_back(new Node(i));
        for (int i{0}; i<n; i++) {
            if (parent[i] == -1) {
                root = treeVec[i];
                continue;
            };
            Node* parNode = treeVec[parent[i]];
            Node* childNode = treeVec[i];
            if (!parNode->left) parNode->left = childNode;
            else parNode->right = childNode;
        }
        return root;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        Node *res = ob.createTree(a, n);
        printLevelOrder(res);
        cout << endl;
    }
    return 0;
}
