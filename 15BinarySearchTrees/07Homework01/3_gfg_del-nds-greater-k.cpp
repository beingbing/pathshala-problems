#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
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

class Solution {
public:
    Node *deleteNode(Node *root, int k) {
        if(!root) return root;
        root->left = deleteNode(root->left, k);
        root->right = deleteNode(root->right, k);
        if(root->data >= k) return root->left;
        return root;
    }
};

int main() {
    int T;
    cin >> T;
    getchar();
    while (T--) {
        Node *root;
        Node *tmp;
        root = NULL;
        string s;
        getline(cin, s);
        root = buildTree(s);
        int k;
        cin >> k;
        getchar();
        Solution obj;
        Node *R = obj.deleteNode(root, k);
        inorder(R);
        cout << endl;
    }
}
