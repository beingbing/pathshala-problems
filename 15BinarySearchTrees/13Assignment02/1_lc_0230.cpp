struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    void traverse(TreeNode* root, int& k, int& cnt, int& ans) {
        if (!root) return;
        traverse(root->left, k, cnt, ans);
        if (cnt++ == k) {
            ans = root->val;
            return;
        }
        traverse(root->right, k, cnt, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 1, ans;
        traverse(root, k, cnt, ans);
        return ans;
    }
};
