#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

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

class Solution {

    void moveLeft(stack<Node*>& stk) {
        Node* n = stk.top();
        stk.pop();
        Node* tmp = n->right;
        while (tmp) {
            stk.push(tmp);
            tmp = tmp->left;
        }
    }

    void moveRight(stack<Node*>& stk) {
        Node* n = stk.top();
        stk.pop();
        Node* tmp = n->left;
        while (tmp) {
            stk.push(tmp);
            tmp = tmp->right;
        }
    }

public:
    int isPairPresent(struct Node *root, int target) {
        stack<Node*> stk1, stk2;
        Node* node = root;
        while (node) {
            stk1.push(node);
            node = node->left;
        }
        node = root;
        while (node) {
            stk2.push(node);
            node = node->right;
        }
        while (stk1.top() != stk2.top()) {
            int x = stk1.top()->data;
            int y = stk2.top()->data;
            if (x+y == target) return true;
            else if (x+y < target) moveLeft(stk1);
            else moveRight(stk2);
        }
        return false;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Solution obj;
        cout << obj.isPairPresent(root, k) << endl;
    }
    return 0;
}
