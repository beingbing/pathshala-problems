#include <iostream>
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
    int totalMoves = 0;

    int traverse(TreeNode *node) {
        if (node == nullptr) return 0;
        int lstMoves = traverse(node->left);
        int rstMoves = traverse(node->right);
        totalMoves += abs(lstMoves) + abs(rstMoves);
        int coinsXtra = node->val + lstMoves + rstMoves - 1; // -1 coz we need to leave a coin for current node
        return coinsXtra;
    }

public:
    int distributeCoins(TreeNode *root) {
        traverse(root);
        return totalMoves;
    }
};
