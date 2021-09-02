
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    
    int ans{0};
    
    void countGP(TreeNode *root) {
        if (!root) return;
        if (root && (root->val)%2 == 0 && root->left && root->left->left)
            ans += root->left->left->val;
        if (root && (root->val)%2 == 0 && root->left && root->left->right)
            ans += root->left->right->val;
        if (root && (root->val)%2 == 0 && root->right && root->right->left)
            ans += root->right->left->val;
        if (root && (root->val)%2 == 0 && root->right && root->right->right)
            ans += root->right->right->val;
        countGP(root->left);
        countGP(root->right);
    }
    
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return ans;
        countGP(root);
        return ans;
    }
};