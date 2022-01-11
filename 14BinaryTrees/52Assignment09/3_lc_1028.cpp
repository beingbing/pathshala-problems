#include <stack>
#include <string>
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
public:
    TreeNode* recoverFromPreorder(string poStr) {
        stack<TreeNode*> stk;
        int i=0, level, val;
        while (i < poStr.length()) {
            for (level = 0; poStr[i] == '-'; i++) level++;
            for (val = 0; i < poStr.length() && poStr[i] != '-'; i++) val = val * 10 + poStr[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (stk.size() > level) stk.pop();
            if (!stk.empty())
                if (!stk.top()->left) stk.top()->left = node;
                else stk.top()->right = node;
            stk.push(node);
        }
        while (stk.size() > 1) stk.pop();
        return stk.top();
    }
};
