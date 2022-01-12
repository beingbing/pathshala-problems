struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBSTIterative(TreeNode* root, int val) {
        TreeNode* node = root;
        while (node) {
            if (node->val == val) return node;
            if (node->val < val) node = node->right;
            else node = node->left;
        }
        return node;
    }

    TreeNode* searchBSTRecursive(TreeNode* root, int val) {
        if (!root || val == root->val) return root;
        if (val < root->val) return searchBSTRecursive(root->left, val);
        return searchBSTRecursive(root->right, val);
    }
};
