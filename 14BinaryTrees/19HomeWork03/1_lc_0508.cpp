#include <iostream>
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
    unordered_map<int, int> sumFreq;
    int mxFreq{0};

    int getPathSum(TreeNode* root) {
        if (!root) return 0;
        int lst = getPathSum(root->left);
        int rst = getPathSum(root->right);
        int sum = root->val + lst + rst;
        sumFreq[sum]++;
        mxFreq = max(mxFreq, sumFreq[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        getPathSum(root);
        vector<int> ans;
        for (auto &ele : sumFreq) if (ele.second == mxFreq) ans.push_back(ele.first);
        return ans;
    }
};
