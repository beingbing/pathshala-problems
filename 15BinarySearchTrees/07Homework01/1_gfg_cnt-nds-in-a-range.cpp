#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
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

// for any tree it will work
int getCountM1(Node *root, int l, int h) {
    int cnt{0};
    if (!root) return cnt;
    if (root->data >= l && root->data <= h) cnt++;
    cnt += getCount(root->left, l, h);
    cnt += getCount(root->right, l, h);
    return cnt;
}

// using BST properties
int getCount(Node *root, int low, int high) {
    if (!root) return 0;
	if (root->data <= high && root->data >= low)
        return 1 + getCount(root->left,low,high) + getCount(root->right,low,high);
	else if (root->data < low) return getCount(root->right, low, high);
	else return getCount(root->left, low, high);
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int l, r;
        cin >> l >> r;
        Node *root = buildTree(s);
        cout << getCount(root, l, r) << endl;
    }
    return 1;
}
