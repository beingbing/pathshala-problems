#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int mx = q.front()->val;
            int sz = q.size();
            while (sz--) {
                TreeNode* n = q.front();
                q.pop();
                mx = max(mx, n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
