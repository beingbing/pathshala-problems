#include <algorithm>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {

    bool ans = true;

    int getHt(TreeNode *root) {
        if (!root) return 0;
        int lst = getHt(root->left);
        int rst = getHt(root->right);
        if (abs(lst - rst) > 1) ans = false;
        return 1 + max(lst, rst);
    }

public:
    bool isBalanced(TreeNode *root) {
        if (!root) true;
        getHt(root);
        return ans;
    }
};

class Solution {
    
    pair<bool, int> func(TreeNode* root) {
        if (!root) return {true, 0};
        pair<bool, int> lst = func(root-> left);
        pair<bool, int> rst = func(root->right);
        bool f = lst.first && rst.first;
        int h1 = lst.second;
        int h2 = rst.second;
        return {f && (abs(h1 - h2) <= 1), 1 + max(h1, h2)};
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return func(root).first;
    }
};