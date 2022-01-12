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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);  
        TreeNode* par = nullptr;
        TreeNode* node = root;
        while (node) {
            par = node;
            if (val > node->val) node = node->right;
            else node = node->left;
        }
        if (val > par->val) par->right = new TreeNode(val);
        else par->left = new TreeNode(val);
        return root;
    }
};
