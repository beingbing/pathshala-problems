#include <iostream>
#include <stack>
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

public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* lastPop = new TreeNode(0);
        while (!stk.empty()) {
            TreeNode* tmp = stk.top();
            stk.pop();
            if (tmp != lastPop && lastPop && tmp->left != lastPop && tmp->right != lastPop
                && (tmp->left || tmp->right)) {
                stk.push(tmp);
                if (tmp->right) stk.push(tmp->right);
                if (tmp->left) stk.push(tmp->left);
            } else ans.push_back(tmp->val), lastPop = tmp;
        }
        return ans;
    }
};
