using namespace std;

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if ((sum - root->val) == 0 && !root->left && !root->right) return true;
        bool lst = hasPathSum(root->left, sum - root->val);
        if (lst) return lst;
        return hasPathSum(root->right, sum - root->val);
    }
};
