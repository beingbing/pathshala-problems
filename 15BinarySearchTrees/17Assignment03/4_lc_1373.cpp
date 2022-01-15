#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SubTreeDetails {
public:
    bool isBST;
    long mn, mx, cnt, subtreeSum;
    SubTreeDetails(bool flag, long mnVal, long mxVal, long cntN, long sum)
        : isBST{flag}, mn{mnVal}, mx{mxVal}, cnt{cntN}, subtreeSum{sum} {}
};


class Solution {

    SubTreeDetails* getLongestBST(TreeNode* root, long& ans) {
        if (!root) return new SubTreeDetails(true, LONG_MAX, LONG_MIN, 0, 0);
        SubTreeDetails* lst = getLongestBST(root->left, ans);
        SubTreeDetails* rst = getLongestBST(root->right, ans);
        bool isBST = false;
        long cnt = 1 + lst->cnt + rst->cnt;
        long mn = min((long) root->val, min(lst->mn, rst->mn));
        long mx = max((long) root->val, max(lst->mx, rst->mx));
        long treeSum = lst->subtreeSum + rst->subtreeSum + root->val;
        if (lst->isBST && rst->isBST && root->val > lst->mx && root->val < rst->mn) {
            ans = max(treeSum, ans);
            isBST = true;
        }
        return new SubTreeDetails(isBST, mn, mx, cnt, treeSum);
    }

public:
    int maxSumBST(TreeNode* root) {
        long ans{0};
        SubTreeDetails* val = getLongestBST(root, ans);
        return ans;
    }
};
