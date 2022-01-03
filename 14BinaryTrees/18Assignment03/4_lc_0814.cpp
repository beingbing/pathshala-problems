#include <iostream>
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

    bool containsOne(TreeNode *node) {
        if (!node) return false;
        bool lst = containsOne(node->left);
        bool rst = containsOne(node->right);
        if (!lst) node->left = nullptr;
        if (!rst) node->right = nullptr;
        return lst || rst || node->val == 1;
    }

public:
    TreeNode *pruneTree(TreeNode *root) {
        return containsOne(root) ? root : nullptr;
    }
};
