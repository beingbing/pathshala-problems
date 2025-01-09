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

    pair<TreeNode*, TreeNode*> convert(TreeNode* root) {
        if (!root) return {nullptr, nullptr};
        pair<TreeNode*, TreeNode*> lst = convert(root->left);
        pair<TreeNode*, TreeNode*> rst = convert(root->right);
        TreeNode* head = root;
        TreeNode* tail = root;
        root->left = nullptr;
        if (lst.first) {
            root->right = lst.first;
            lst.second->right = rst.first;
            if (rst.first) tail = rst.second;
            else tail = lst.second;
        } else if (rst.first) {
            root->right = rst.first;
            tail = rst.second;
        }
        return {head, tail};
    }

public:
    void flatten(TreeNode* root) {
        root = convert(root).first;
    }
};
