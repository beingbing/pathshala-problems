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
    int idx{0};

    void traverse(TreeNode* root, vector<int>& voyage) {
        if (!root) return;
        if (root->val != voyage[idx++]) {
            ans.clear();
            ans.push_back(-1);
            return;
        }
        if (idx < voyage.size() && root->left and root->left->val != voyage[idx]) {
            ans.push_back(root->val);
            traverse(root->right, voyage);
            traverse(root->left, voyage);
        } else {
            traverse(root->left, voyage);
            traverse(root->right, voyage);
        }
    }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        traverse(root, voyage);
        if (ans.size() > 1 && ans[0] == -1) ans.clear(), ans.push_back(-1);
        return ans;
    }
};
