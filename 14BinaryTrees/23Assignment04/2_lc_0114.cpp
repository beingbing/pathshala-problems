// as there can never a full binary tree with even number of nodes, so omitting count of those.
#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, vector<TreeNode*>> nodesCnt;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (nodesCnt.find(n) == nodesCnt.end()) {
            vector<TreeNode*> ans;
            if (n == 1) ans.push_back(new TreeNode(0));
            else if (n % 2 == 1) {
                for (int x = 1; x < n; x += 2) {
                    vector<TreeNode *> lst = allPossibleFBT(x);
                    vector<TreeNode *> rst = allPossibleFBT(n - 1 - x);
                    for (TreeNode* &left: lst)
                        for (TreeNode* &right: rst) {
                            TreeNode* root = new TreeNode(0);
                            root->left = left;
                            root->right = right;
                            ans.push_back(root);
                        }
                }
            }
            nodesCnt[n] = ans;
        }
        return nodesCnt[n];
    }
};
