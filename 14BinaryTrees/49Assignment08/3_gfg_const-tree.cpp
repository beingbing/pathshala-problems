#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void printInorder(Node *Node) {
    if (Node == NULL) return;
    printInorder(Node->left);
    printf("%d ", Node->data);
    printInorder(Node->right);
}

Node *constructTree(vector<int>& pre, vector<char>& preLN, int& idx, int& n) {
    int i = idx;
    if (i == n) return nullptr;
    Node *temp = new Node(pre[i]);
    idx++;
    if (preLN[i] == 'N') {
        temp->left = constructTree(pre, preLN, idx, n);
        temp->right = constructTree(pre, preLN, idx, n);
    }
    return temp;
}


int main() {
    Node *root = nullptr;
    vector<int> pre = {10, 30, 20, 5, 15};
    vector<char> preLN = {'N', 'N', 'L', 'L', 'L'};
    int n{5}, idx{0};
    root = constructTree(pre, preLN, idx, n);
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder(root);
    cout << endl;
    return 0;
}
