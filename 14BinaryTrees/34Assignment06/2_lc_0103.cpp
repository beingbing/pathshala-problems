#include <queue>
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
    vector<vector<int>> ans;

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        stack<int> stk;
        while (!q.empty()) {
            vector<int> row;
            int sz = q.size();
            while (sz--) {
                TreeNode *n = q.front();
                q.pop();
                if (level % 2 != 0) stk.push(n->val);
                else row.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            if (level % 2 != 0) {
                while (!stk.empty()) {
                    row.push_back(stk.top());
                    stk.pop();
                }
            }
            ans.push_back(row);
            level++;
        }
        return ans;
    }
};
