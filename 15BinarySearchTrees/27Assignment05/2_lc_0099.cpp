#include <algorithm>
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

    void inorder(TreeNode* root, TreeNode*& prv, TreeNode*& n1, TreeNode*& n2, TreeNode*& n3, int& cnt) {
        if (!root) return;
        inorder(root->left, prv, n1, n2, n3, cnt);
        if (!prv) prv = root;
        else {
            if (root->val < prv->val) {
                cnt++;
                if (cnt == 1) n1 = prv, n2 = root;
                else if (cnt == 2) n3 = root;
            }
            prv = root;
        }
        inorder(root->right, prv, n1, n2, n3, cnt);
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode *n1, *n2, *n3, *prv = NULL;
        int cnt = 0;
        inorder(root, prv, n1, n2, n3, cnt);
        if (cnt == 1) swap(n1->val, n2->val);
        else if (cnt == 2) swap(n1->val, n3->val);
    }
};
