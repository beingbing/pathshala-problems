#include <iostream>
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

class Traverse {
    vector<vector<int>> ans;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> row;
            int sz = q.size();
            while (sz--) {
                TreeNode* n = q.front();
                q.pop();
                row.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};

class Solution {

    TreeNode *build(int ps, int pe, vector<int> &preorder, int is, int ie, vector<int> &inorder) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode *root = new TreeNode(preorder[ps], NULL, NULL);
        int i;
        for (i = is; i <= ie; i++) if (inorder[i] == preorder[ps]) break;
        root->left = build(ps + 1, (ps + 1) + (i - is - 1), preorder, is, i - 1, inorder);
        root->right = build((ps + 1) + (i - is - 1) + 1, pe, preorder, i + 1, ie, inorder);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (!n) return nullptr;
        return build(0, n-1, preorder, 0, n-1, inorder);
    }
};

int main() {
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    Solution obj;
    TreeNode* rut = obj.buildTree(preorder, inorder);
    Traverse trv;
    vector<vector<int>> ans = trv.levelOrder(rut);
    for (auto &rw : ans) {
        for (auto &ele : rw) cout << ele << " ";
        cout << endl;
    }
    return 0;
}
