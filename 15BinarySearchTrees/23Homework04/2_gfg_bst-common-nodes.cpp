#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
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

class Solution {
    vector<int> ans;

    void checkExistence(Node* root, int val) {
        if (!root) return;
        if (root->data == val) {
            ans.push_back(val);
            return;
        } else if (root->data > val) checkExistence(root->left, val);
        else checkExistence(root->right, val);
    }

    void findElement(Node* root1, Node* root2) {
        if (!root1) return;
        findElement(root1->left, root2);
        checkExistence(root2, root1->data);
        findElement(root1->right, root2);
    }
public:
    vector<int> findCommon(Node *root1, Node *root2) {
        findElement(root1, root2);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);
        getline(cin, s);
        Node *root2 = buildTree(s);
        Solution ob;
        vector<int> res = ob.findCommon(root1, root2);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 1;
}
