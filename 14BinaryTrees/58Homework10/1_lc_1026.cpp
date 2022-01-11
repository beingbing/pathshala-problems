#include <algorithm>
#include <climits>
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
    int ans{0};
    pair<int, int> traverse(TreeNode* root) {
        if (!root) return {INT_MAX, INT_MIN};
        if (!root->left && !root->right) return {root->val, root->val};
        pair<int, int> lst = traverse(root->left);
        pair<int, int> rst = traverse(root->right);
        int mn = min(lst.first, rst.first);
        int mx = max(lst.second, rst.second);
        ans = max(ans, max(abs(mx - root->val), abs(root->val - mn)));
        mn = min(root->val, mn);
        mx = max(root->val, mx);
        return {mn, mx};
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return ans;
        traverse(root);
        return ans;
    }
};
