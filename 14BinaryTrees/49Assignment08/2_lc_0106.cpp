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

    TreeNode *build(int ps, int pe, vector<int> &postorder, int is, int ie, vector<int> &inorder) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode *root = new TreeNode(postorder[pe], NULL, NULL);
        int i;
        for (i = is; i <= ie; i++) if (inorder[i] == postorder[pe]) break;
        root->left = build(ps, (ps + 1) + (i - is - 1) - 1, postorder, is, i - 1, inorder);
        root->right = build((ps + 1) + (i - is - 1), pe - 1, postorder, i + 1, ie, inorder);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if (!n) return nullptr;
        return build(0, n-1, postorder, 0, n-1, inorder);
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    Solution obj;
    TreeNode* rut = obj.buildTree(inorder, postorder);
    Traverse trv;
    vector<vector<int>> ans = trv.levelOrder(rut);
    for (auto &rw : ans) {
        for (auto &ele : rw) cout << ele << " ";
        cout << endl;
    }
    return 0;
}
