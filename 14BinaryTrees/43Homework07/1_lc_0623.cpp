#include <iostream>
#include <queue>
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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* nwRt = new TreeNode(val);
            nwRt->left = root;
            return nwRt;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            depth--;
            while (sz--) {
                TreeNode* n = q.front();
                q.pop();
                if (depth == 1) {
                    TreeNode* tmp = n->left;
                    n->left = new TreeNode(val);
                    n->left->left = tmp;
                    tmp = n->right;
                    n->right = new TreeNode(val);
                    n->right->right = tmp;
                }
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return root;
    }
};
