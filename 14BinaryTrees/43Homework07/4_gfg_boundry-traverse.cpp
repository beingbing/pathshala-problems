#include <iostream>
#include <queue>
#include <stack>
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
public:
    bool isLeaf(Node *root) {
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node *root, vector<int> &ans) {
        Node *curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) ans.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(Node *root, vector<int> &ans) {
        Node *curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i{temp.size()-1}; i >= 0; i--) ans.push_back(temp[i]);
    }

    void addLeaves(Node *root, vector<int> &ans) {
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, ans);
        if (root->right) addLeaves(root->right, ans);
    }

    vector<int> boundary(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
