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

class Solution {
    vector<int> ans;

    void traverse(Node *root, int lvl, int &mxL) {
        if (!root) return;
        if (lvl > mxL) {
            ans.push_back(root->data);
            mxL = lvl;
        }
        traverse(root->right, lvl + 1, mxL);
        traverse(root->left, lvl + 1, mxL);
    }

public:
    vector<int> rightView(Node *root) {
        int mxL{-1};
        traverse(root, 0, mxL);
        return ans;
    }
};

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

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> vec = ob.rightView(root);
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    return 0;
}
