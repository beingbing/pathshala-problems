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

    pair<bool, int> isPerfect(TreeNode* root) {
        TreeNode* tmp = root;
        int hleft = 0;
        while (tmp) hleft++, tmp = tmp->left;
        tmp = root;
        int hright = 0;
        while (tmp) hright++, tmp = tmp->right;
        return {hleft == hright, hleft};
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int cnt = 1;
        pair<bool, int> pleft = isPerfect(root->left);
        pair<bool, int> pright = isPerfect(root->right);
        if (pleft.first) cnt += pow(2, pleft.second) - 1;
        else cnt += countNodes(root->left);
        if (pright.first) cnt += pow(2, pright.second) - 1;
        else cnt += countNodes(root->right);
        return cnt;
    }
};
