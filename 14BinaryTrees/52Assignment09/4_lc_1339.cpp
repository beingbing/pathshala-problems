#include <vector>
using namespace std;
typedef long long int ll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<ll> allSubtreeSums;

    ll subtreeSum(TreeNode* root) {
        ll sum{0};
        if (!root) return sum;
        sum += root->val;
        sum += subtreeSum(root->left);
        sum += subtreeSum(root->right);
        allSubtreeSums.push_back(sum);
        return sum;
    }

public:
    int maxProduct(TreeNode* root) {
        ll totalSum{0};
        totalSum = subtreeSum(root);
        ll ans{0};
        for (auto &sum : allSubtreeSums) ans = max(ans, sum * (totalSum - sum));
        return ans % (int) (1e9 + 7);
    }
};
