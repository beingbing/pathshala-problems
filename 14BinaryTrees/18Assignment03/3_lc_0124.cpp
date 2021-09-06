#include <algorithm>
#include <utility>
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
    
    pair<int, int> getMaxPath(TreeNode* root) {
        if (!root) return {INT_MIN,0};
        pair<int, int> lst = getMaxPath(root->left);
        pair<int, int> rst = getMaxPath(root->right);
        int ans1 = lst.first;
        int uniPath1 = lst.second;
        int ans2 = rst.first;
        int uniPath2 = rst.second;
        int ans = max(ans1, ans2);
        ans = max(ans, root->val + max(0, uniPath1) + max(0, uniPath2));
        int uniPath = root->val + max(0, max(uniPath1, uniPath2));
        return {ans, uniPath};
    }
    
public:
    int maxPathSum(TreeNode* root) {
        return getMaxPath(root).first;
    }
};

// TC = O(N)
// SC = O(H)