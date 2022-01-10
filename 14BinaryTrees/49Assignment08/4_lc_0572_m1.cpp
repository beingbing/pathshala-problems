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
    
    bool areSame(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return t1->val == t2->val && areSame(t1->left, t2->left) && areSame(t1->right, t2->right);
    }
    
public:
    bool isSubtree(TreeNode* r1, TreeNode* r2) {
        if (areSame(r1, r2)) return true;
        if (!r1) return false;
        bool lst = isSubtree(r1->left, r2);
        if (lst) return true;
        return isSubtree(r1->right, r2);
    }
};
