#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_set<TreeNode *> visited;

    void findParent(TreeNode *node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        findParent(node->left, node);
        findParent(node->right, node);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        if (!root) return {};
        findParent(root, nullptr);
        dfs(target, K);
        return ans;
    }

    void dfs(TreeNode *node, int K) {
        if (!node) return;
        if (visited.count(node) > 0) return;
        visited.insert(node);
        if (K == 0) {
            ans.push_back(node->val);
            return;
        }
        dfs(node->left, K - 1);
        dfs(node->right, K - 1);
        dfs(parent[node], K - 1);
    }
};
