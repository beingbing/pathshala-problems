#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

void inorder(Node *node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

Node *RemoveHalfNodes(Node *root) {
    if(!root) return root;
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    if(!root->left && root->right) return root->right;
    if(root->left && !root->right) return root->left;
    return root;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Node *fresh = RemoveHalfNodes(root);
        inorder(fresh);
        cout << endl;
    }
    return 1;
}
