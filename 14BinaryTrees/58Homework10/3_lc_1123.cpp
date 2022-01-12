#include <unordered_map>
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
    unordered_map<TreeNode*, int> depth;

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!depth.count(root)) depth[root] = 1 + max(maxDepth(root->left), maxDepth(root->right));
        return depth[root];
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return nullptr;
        int lst = maxDepth(root->left);
        int rst = maxDepth(root->right);
        if(lst == rst) return root;
        else if(lst < rst) return lcaDeepestLeaves(root->right);
        else return lcaDeepestLeaves(root->left);
    }
};
