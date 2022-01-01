#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    TreeNode *checkNode(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (!original) return NULL;
        if (original->val == target->val) return cloned;
        TreeNode *lft = checkNode(original->left, cloned->left, target);
        if (lft) return lft;
        TreeNode *rgt = checkNode(original->right, cloned->right, target);
        if (rgt) return rgt;
        return NULL;
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (original->val == target->val) return cloned;
        return checkNode(original, cloned, target);
    }
};
