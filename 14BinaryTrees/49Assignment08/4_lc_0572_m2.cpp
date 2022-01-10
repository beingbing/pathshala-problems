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

    void preorder(TreeNode *root, vector<int> &po) {
        if (!root) {
            po.push_back(100001);
            return;
        }
        po.push_back(root->val);
        preorder(root->left, po);
        preorder(root->right, po);
    }

public:
    bool isSubtree(TreeNode *r1, TreeNode *r2) {
        vector<int> po1, po2;
        preorder(r1, po1);
        preorder(r2, po2);
        if (po1.size() < po2.size()) return false;
        for (int i{0}; i <= po1.size() - po2.size(); i++) {
            int c = 0;
            for (int j = i; j < i + po2.size(); j++) if (po1[j] == po2[j - i]) c++;
            if (c == po2.size()) return true;
        }
        return false;
    }
};
