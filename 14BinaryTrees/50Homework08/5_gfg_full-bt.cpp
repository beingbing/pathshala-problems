// i do not have a card for this
#include <iostream>
#include <stack>
#include <unordered_map>
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

void printInorder(Node *node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

Node *constructBinaryTree(int pre[], int preMirror[], int size) {
    if (size == 0) return NULL;
    unordered_map<int, int> mp;
    Node *root = new Node(pre[0]);
    stack<Node *> st;
    st.push(root);
    for (int i = 0; i < size; i++) mp[preMirror[i]] = i;
    int i = 1;
    while (i < size) {
        int data = pre[i];
        Node *res = new Node(data);
        while (!st.empty()) {
            Node *temp = st.top();
            if (mp[temp->data] < mp[data]) {
                if (!temp->left) {
                    temp->left = res;
                    st.push(res);
                } else {
                    temp->right = res;
                    st.pop();
                    st.push(res);
                }
                break;
            } else st.pop();
        }
        i++;
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int preOrder[n];
        int preOrderMirror[n];
        for (int i = 0; i < n; i++) cin >> preOrder[i];
        for (int i = 0; i < n; i++) cin >> preOrderMirror[i];
        printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
        cout << endl;
    }
    return 0;
}
