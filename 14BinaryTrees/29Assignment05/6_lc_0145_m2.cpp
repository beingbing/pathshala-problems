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
        stack<TreeNode*> stk;
        TreeNode *lastPop = nullptr, *tmp = root;
        while (tmp || !stk.empty()) {
            if (tmp) {
                stk.push(tmp);
                tmp = tmp->left;
            } else {
                TreeNode* node = stk.top();
                if (node->right && lastPop != node->right) tmp = node->right;
                else {
                    ans.push_back(node->val);
                    lastPop = node;
                    stk.pop();
                }
            }
        }
        return ans;
    }
};
