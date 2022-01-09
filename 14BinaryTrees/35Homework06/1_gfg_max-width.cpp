#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

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
public:
    int getMaxWidth(Node *root) {
        if (!root) return 0;
        int mx{0};
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            mx = max(mx, sz);
            while (sz--) {
                Node* n = q.front();
                q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return mx;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string inp;
        getline(cin, inp);
        Node *root = buildTree(inp);
        Solution ob;
        cout << ob.getMaxWidth(root) << endl;
    }
    return 0;
}