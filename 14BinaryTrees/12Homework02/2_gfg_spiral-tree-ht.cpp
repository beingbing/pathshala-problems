#include <algorithm>
#include <iostream>
#include <queue>
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

void saveLeafNodes(Node *root, vector<Node *> &leaf) {
    if (!root) return;
    saveLeafNodes(root->left, leaf);
    if (root->left == NULL && root->right == NULL) leaf.push_back(root);
    saveLeafNodes(root->right, leaf);
}

void linkLeafNodes(Node *root) {
    vector<Node *> leaf;
    saveLeafNodes(root, leaf);
    if (leaf.size() <= 1) return;
    for (int i = 0; i < leaf.size(); i++) {
        if (i == 0) {
            leaf[i]->right = leaf[i + 1];
            leaf[i]->left = leaf[leaf.size() - 1];
        } else if (i == leaf.size() - 1) {
            leaf[i]->right = leaf[0];
            leaf[i]->left = leaf[i - 1];
        } else {
            leaf[i]->right = leaf[i + 1];
            leaf[i]->left = leaf[i - 1];
        }
    }
    return;
}

int findTreeHeight(Node *root) {
    if (!root) return 0;
    if (root->left && root->left->right == root && root->right && root->right->left == root) return 1;
    return 1 + max(findTreeHeight(root->left), findTreeHeight(root->right));
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        linkLeafNodes(root);
        int h = findTreeHeight(root);
        cout << h << endl;
    }
    return 1;
}
