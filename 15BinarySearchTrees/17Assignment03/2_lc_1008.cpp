#include <stack>
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

    TreeNode* makeBST(vector<int>& p, int i, int j, vector<int>& NGE) {
        if (i>j) return NULL;
        TreeNode* node = new TreeNode(p[i], NULL, NULL);
        node->left = makeBST(p, i+1, NGE[i]-1, NGE);
        node->right = makeBST(p, NGE[i], j, NGE);
        return node;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> NGE(n);
        stack<int> stk;
        stk.push(0);
        for (int i{1}; i<n; i++) {
            while (!stk.empty() && preorder[i] > preorder[stk.top()]) {
                NGE[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            NGE[stk.top()] = n;
            stk.pop();
        }
        return makeBST(preorder, 0, n-1, NGE);
    }
};
