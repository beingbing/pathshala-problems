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
    pair<TreeNode*, TreeNode*> getNodeAndParent(TreeNode* root, int key) {
        TreeNode* node = root;
        TreeNode* par = nullptr;
        while (node) {
            if (node->val == key) break;
            par = node;
            if (key > node->val) node = node->right;
            else node = node->left;
        }
        return {node, par};
    }

    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    TreeNode* deleteLeaf(TreeNode* node, TreeNode* par) {
        if (par->left == node) par->left = NULL;
        else par->right = NULL;
        return node;
    }

    bool hasSingleChild(TreeNode* node) {
        return ((node->left && !node->right) || (!node->left && node->right));
    }

    TreeNode* deleteSingleChildNode(TreeNode* node, TreeNode* par) {
        if (node->left) {
            if (par->right == node) par->right = node->left;
            else par->left = node->left;
            node->left = NULL;
        } else {
            if (par->right == node) par->right = node->right;
            else par->left = node->right;
            node->right = NULL;
        }
        return node;
    }

    TreeNode* deleteDoubleChildNode(TreeNode* node, TreeNode* par) {
        TreeNode* parent = node;
        TreeNode* inorderPredecessor = node->left;
        while (inorderPredecessor->right) {
            parent = inorderPredecessor;
            inorderPredecessor = inorderPredecessor->right;
        }
        TreeNode* n1;
        if (isLeaf(inorderPredecessor)) n1 = deleteLeaf(inorderPredecessor, parent);
        else n1 = deleteSingleChildNode(inorderPredecessor, parent);
        if (par && par->left == node) par->left = n1;
        else if (par) par->right = n1;
        n1->left = node->left;
        n1->right = node->right;
        return node;
    }

    TreeNode* deleteRoot(TreeNode* root) {
        if (isLeaf(root)) {
            delete(root);
            return nullptr;
        }
        if (hasSingleChild(root)) {
            TreeNode* ans = root->left ? root->left : root->right;
            delete(root);
            return ans;
        }
        TreeNode* ans = root->left;
        while (ans->right) ans = ans->right;
        TreeNode* node = deleteDoubleChildNode(root, NULL);
        delete(node);
        return ans;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        pair<TreeNode*, TreeNode*> p = getNodeAndParent(root, key);
        if (!p.first) return root;
        if (p.first == root) return deleteRoot(root);
        TreeNode* node;
        if (isLeaf(p.first)) node = deleteLeaf(p.first, p.second);
        else if (hasSingleChild(p.first)) node = deleteSingleChildNode(p.first, p.second);
        else node = deleteDoubleChildNode(p.first, p.second);
        delete(node);
        return root;
    }
};
