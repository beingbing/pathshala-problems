#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
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
    Node *lowestCommonAncestor(Node *root, int &p, int &q) {
        if (!root) return NULL;
        if (root->data == p || root->data == q) return root;
        Node *lst = lowestCommonAncestor(root->left, p, q);
        Node *rst = lowestCommonAncestor(root->right, p, q);
        if (!lst) return rst;
        if (!rst) return lst;
        return root;
    }

    void findTurns(Node *root, int a, int cur, int &trns, string s) {
        if (!root) return;
        if (root->data == a) {
            trns += cur;
            return;
        }
        if (s == "null") {
            findTurns(root->left, a, cur, trns, "left");
            findTurns(root->right, a, cur, trns, "right");
        } else {
            if (s == "left") {
                findTurns(root->left, a, cur, trns, "left");
                findTurns(root->right, a, cur + 1, trns, "right");
            } else {
                findTurns(root->left, a, cur + 1, trns, "left");
                findTurns(root->right, a, cur, trns, "right");
            }
        }
    }

public:
    int NumberOFTurns(struct Node *root, int frst, int scnd) {
        Node *lca = lowestCommonAncestor(root, frst, scnd);
        int trns = 0;
        if (lca->data != frst && lca->data != scnd) trns++;
        findTurns(lca, frst, 0, trns, "null");
        findTurns(lca, scnd, 0, trns, "null");
        return trns;
    }
};

int main() {
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        int turn, first, second;
        cin >> first >> second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second))) cout << turn << endl;
        else cout << "-1\n";
        cin.ignore();
    }
    return 0;
}
