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

    void checkExistence(Node* root, int val, int& cnt) {
        if (!root) return;
        if (root->data == val) {
            cnt++;
            return;
        } else if (root->data > val) checkExistence(root->left, val, cnt);
        else checkExistence(root->right, val, cnt);
    }

    void findPairs(Node* root1, Node* root2, int target, int& cnt) {
        if (!root1) return;
        findPairs(root1->left, root2, target, cnt);
        checkExistence(root2, target - root1->data, cnt);
        findPairs(root1->right, root2, target, cnt);
    }
public:
    int countPairs(Node *root1, Node *root2, int x) {
        int cnt{0};
        findPairs(root1, root2, x, cnt);
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node *root1 = buildTree(tree1);
        Node *root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}
