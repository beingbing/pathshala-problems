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
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void store(Node* root, vector<int>& vals) {
    if (!root) return;
    store(root->left, vals);
    vals.push_back(root->data);
    store(root->right, vals);
}

float findMedian(struct Node *root) {
    vector<int> vals;
    store(root, vals);
    if (vals.size() % 2 == 0) return (float)(vals[vals.size() / 2] + vals[(vals.size() / 2) - 1]) / 2;
    else return vals[vals.size() / 2];
}

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

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        cout << findMedian(root) << endl;
    }
    return 0;
}
