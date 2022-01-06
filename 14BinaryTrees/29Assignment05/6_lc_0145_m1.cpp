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
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode *> stk;
        stk.push(root);
        stk.push(root);
        TreeNode *cur;
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            if (!stk.empty() && stk.top() == cur) {
                if (cur->right) {
                    stk.push(cur->right);
                    stk.push(cur->right);
                }
                if (cur->left) {
                    stk.push(cur->left);
                    stk.push(cur->left);
                }
            } else ans.push_back(cur->val);
        }
        return ans;
    }
};
