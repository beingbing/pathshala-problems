#include <unordered_map>
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
    int count = 0;
    int k;
    unordered_map<int, int> h;

    void preorder(TreeNode* node, int currSum) {
        if (!node) return;
        currSum += node->val;
        if (currSum == k) count++;
        count += h[currSum - k];
        h[currSum]++;
        preorder(node->left, currSum);
        preorder(node->right, currSum);
        h[currSum]--;
    }    

public:
    int pathSum(TreeNode* root, int sum) {
        k = sum;
        preorder(root, 0);
        return count;
    }
};
