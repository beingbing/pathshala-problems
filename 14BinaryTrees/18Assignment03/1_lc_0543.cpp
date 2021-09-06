// here they defined ht with respect to edges hence
// dia formula changed to
// dia = max(dia(LST), dia(RST), ht(LST)+ht(RST))
// if ht is defined w r to nodes then
// dia = max(dia(LST), dia(RST), 1+ht(LST)+ht(RST))
#include <utility>
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
    
    pair<int, int> getHtAndDia(TreeNode* root) {
        if (!root) return {0,0};
        pair<int, int> lst = getHtAndDia(root->left);
        pair<int, int> rst = getHtAndDia(root->right);
        int h1 = lst.first;
        int d1 = lst.second;
        int h2 = rst.first;
        int d2 = rst.second;
        int h = 1 + max(h1, h2);
        int d = max(d1, d2);
        d = max(d, h1 + h2);
        return {h, d};
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        return getHtAndDia(root).second;
    }
};