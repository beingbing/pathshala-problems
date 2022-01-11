#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node *left;
    Node *right;
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

class Solution {

    int findLevel(Node *root, int k, int level) {
        if (root == NULL) return -1;
        if (root->data == k) return level;
        int l = findLevel(root->left, k, level + 1);
        return (l != -1) ? l : findLevel(root->right, k, level + 1);
    }

    Node* lowestCommonAncestor(Node* root, int& p, int& q) {
        if (!root) return NULL;
        if (root->data == p || root->data == q) return root;
        Node* lst = lowestCommonAncestor(root->left, p, q);
        Node* rst = lowestCommonAncestor(root->right, p, q);
        if (!lst) return rst;
        if (!rst) return lst;
        return root;
    }

public:
    int findDist(Node *root, int n1, int n2) {
        int d1 = -1, d2 = -1, dist;
        Node *lca = lowestCommonAncestor(root, n1, n2);
        d1 = findLevel(root, n1, 0);
        d2 = findLevel(root, n2, 0);
        dist = findLevel(root, lca->data, 0);
        return d1 + d2 - 2*dist;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    cout << "t: " << endl;
    while (t--) {
        string s, ch;
        getline(cin, s);
        cout << "s: " << s << endl;
        Node *root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << "n1: " << n1 << " n2: " << n2 << endl;
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
    }
    return 0;
}
