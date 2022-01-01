#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
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

bool isCousins(Node *root, int x, int y);

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        if (x == y) {
            cout << "0\n";
            continue;
        }
        cout << isCousins(root, x, y) << endl;
    }
    return 1;
}

bool siblings(Node *root, int &a, int &b) {
    if (!root) return false;
    if (!(root->left) || !(root->right)) return false;
    return (root->left->data == a && root->right->data == b) || (root->right->data == a && root->left->data == b) || siblings(root->left, a, b) || siblings(root->right, a, b);
}

int findLevel(Node *root, int &target, int level) {
    if (!root) return 0;
    if (root->data == target) return level;
    int lft = findLevel(root->left, target, level + 1);
    if (lft) return lft;
    return findLevel(root->right, target, level + 1);
}

bool onSameLevel(Node *root, int &a, int &b) {
    if (findLevel(root, a, 1) == findLevel(root, b, 1)) return true;
    return false;
}

bool isCousins(Node *root, int a, int b) {
    if (onSameLevel(root, a, b) && !siblings(root, a, b)) return true;
    return false;
}
