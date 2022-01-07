#include <queue>
using namespace std;
typedef unsigned long long int ull;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        ull mx{0};
        queue<pair<TreeNode *, ull>> q;
        q.push({root, 1});
        while (!q.empty()) {
            ull fst = q.front().second;
            int sz = q.size();
            while (sz--) {
                pair<TreeNode *, ull> n = q.front();
                q.pop();
                if (!sz) mx = max((ull) mx, (ull) n.second - fst + 1);
                if (n.first->left) q.push({n.first->left, (ull) 2*(n.second)});
                if (n.first->right) q.push({n.first->right, (ull) 2*(n.second)+1});
            }
        }
        return mx;
    }
};
