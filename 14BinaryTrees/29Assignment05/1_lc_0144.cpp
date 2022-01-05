#include <iostream>
#include <vector>
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
    vector<int> ans;

    void traverse(TreeNode* root) {
        if (!root) return;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return ans;
    }
};
