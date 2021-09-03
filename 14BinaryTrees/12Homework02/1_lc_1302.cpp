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
    vector<vector<int>> paths;
    vector<int> vec;
    int mx{0}, ans{0};
    
    void getAllPaths(TreeNode *root) {
        if (!root) return;
        vec.push_back(root->val);
        if (!(root->left) && !(root->right)) {
            if (mx < vec.size()) mx = vec.size();
            paths.push_back(vec);
        } else {
            getAllPaths(root->left);
            getAllPaths(root->right);
        }
        vec.pop_back();
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        getAllPaths(root);
        for (auto path : paths) if (path.size() == mx) ans += path[mx-1];
        return ans;
    }
};