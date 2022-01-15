#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) {
        TreeNode* node = root;
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode* ans = stk.top();
        stk.pop();
        TreeNode* node = ans->right;
        while (node) {
            stk.push(node);
            node = node->left;
        }
        return ans->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};
