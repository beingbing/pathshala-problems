#include <iostream>
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
    vector<string> ans;
    vector<int> vec;

    void printAllPaths(TreeNode *root) {
        if (!root) return;
        vec.push_back(root->val);
        if (!(root->left) && !(root->right)) {
            string str;
            for (int i{0}; i < vec.size(); i++) {
                if (i) str += "->";
                str += to_string(vec[i]);
            }
            ans.push_back(str);
        } else {
            printAllPaths(root->left);
            printAllPaths(root->right);
        }
        vec.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        printAllPaths(root);
        return ans;
    }
};