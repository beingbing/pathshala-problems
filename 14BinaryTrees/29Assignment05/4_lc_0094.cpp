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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* tmp = root;
        while (tmp) {
            stk.push(tmp);
            tmp = tmp->left;
        }
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            ans.push_back(p->val);
            TreeNode* r = p->right;
            while (r) {
                stk.push(r);
                r = r->left;
            }
        }
        return ans;
    }
};
