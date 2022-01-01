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
    int sum{0};

    void countLeaves(TreeNode *root) {
        if (!root) return;
        if (root && root->left && !(root->left->left) && !(root->left->right)) sum += root->left->val;
        countLeaves(root->left);
        countLeaves(root->right);
    }

public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        countLeaves(root);
        return sum;
    }
};
