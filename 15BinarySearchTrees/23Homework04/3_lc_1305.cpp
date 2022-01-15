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

    void moveLeft(stack<TreeNode*>& stk) {
        TreeNode* n = stk.top();
        stk.pop();
        TreeNode* tmp = n->right;
        while (tmp) {
            stk.push(tmp);
            tmp = tmp->left;
        }
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> stk1, stk2;
        TreeNode* node = root1;
        while (node) {
            stk1.push(node);
            node = node->left;
        }
        node = root2;
        while (node) {
            stk2.push(node);
            node = node->left;
        }
        while (!stk1.empty() && !stk2.empty()) {
            int x = stk1.top()->val;
            int y = stk2.top()->val;
            if (x < y) {
                ans.push_back(x);
                moveLeft(stk1);
            } else {
                ans.push_back(y);
                moveLeft(stk2);
            }
        }
        while (!stk1.empty()) {
            ans.push_back(stk1.top()->val);
            moveLeft(stk1);
        }
        while (!stk2.empty()) {
            ans.push_back(stk2.top()->val);
            moveLeft(stk2);
        }
        return ans;
    }
};
