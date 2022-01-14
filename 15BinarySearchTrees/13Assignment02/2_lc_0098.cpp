#include <climits>
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

    void check(TreeNode* node, long lb, long ub, bool& ans) {
        if (!node) return;
        if (node->val <= lb || node->val >= ub) {ans = false; return;}
        check(node->left, lb, node->val, ans);
        check(node->right, node->val, ub, ans);
    }

public:
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        check(root, LONG_MIN, LONG_MAX, ans);
        return ans;
    }
};
