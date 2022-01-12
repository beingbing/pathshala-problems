#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<vector<int>> ans;

    void currStatus(TreeNode* root, vector<int> &path, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (sum - root->val == 0 && !root->left && !root->right) ans.push_back(path);
        currStatus(root->left, path, sum - root->val);
        currStatus(root->right, path, sum - root->val);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        currStatus(root, path, sum);
        return ans;
    }
    
};
