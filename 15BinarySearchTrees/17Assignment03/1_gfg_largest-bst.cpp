#include <algorithm>
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

class SubTreeDetails {
public:
    bool isBST;
    long mn, mx, cnt;
    SubTreeDetails(bool flag, long mnVal, long mxVal, long cntN): isBST{flag}, mn{mnVal}, mx{mxVal}, cnt{cntN} {}
};

class Solution {

    SubTreeDetails* getLongestBST(Node* root, long& ans) {
        if (!root) return new SubTreeDetails(true, LONG_MAX, LONG_MIN, 0);
        SubTreeDetails* lst = getLongestBST(root->left, ans);
        SubTreeDetails* rst = getLongestBST(root->right, ans);
        bool isBST = false;
        long cnt = 1 + lst->cnt + rst->cnt;
        long mn = min((long) root->data, min(lst->mn, rst->mn));
        long mx = max((long) root->data, max(lst->mx, rst->mx));
        if (lst->isBST && rst->isBST && root->data > lst->mx && root->data < rst->mn) {
            ans = max(ans, cnt);
            isBST = true;
        }
        return new SubTreeDetails(isBST, mn, mx, cnt);
    }

public:
    int largestBst(Node *root) {
        long ans{0};
        SubTreeDetails* val = getLongestBST(root, ans);
        return ans;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
