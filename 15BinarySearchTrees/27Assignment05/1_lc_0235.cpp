#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val == p->val || root->val == q->val) return root;
        int mx = max(p->val, q->val);
        int mn = min(p->val, q->val);
        if (root->val > mn && root->val < mx) return root;
        if (root->val < mn && root->val < mx) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};
