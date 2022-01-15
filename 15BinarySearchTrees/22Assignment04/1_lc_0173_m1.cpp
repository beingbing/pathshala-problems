#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    vector<int> inorder;
    int c = 0;

    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        return inorder[c++];
    }
    
    bool hasNext() {
        return c < inorder.size();
    }
};
