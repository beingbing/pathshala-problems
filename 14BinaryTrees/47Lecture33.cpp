#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// to construct preorder array
void preorder(Node* root, vector<int>& po) {
    if (!root) {
        po.push_back(0);
        return;
    }
    po.push_back(root->data);
    preorder(root->left, po);
    preorder(root->right, po);
}

// to construct tree from preorder
Node* makeTree(vector<int>& po, int& i) {
    if (po[i] == 0) {
        i++;
        return NULL;
    }
    Node* n = newNode(po[i]);
    i++;
    n->left = makeTree(po, i);
    n->right = makeTree(po, i);
    return n;
}

bool isSameTree(Node* p, Node* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> po;
        preorder(root, po);
        int i = 0;
        Node *rut = makeTree(po, i);
        if (isSameTree(root, rut)) cout << "yes" << endl;
        else cout << "no" << endl;
        cout << endl;
    }
}