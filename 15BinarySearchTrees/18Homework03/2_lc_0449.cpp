#include <climits>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {

    void preTraverse(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            preTraverse(root->left, out);
            preTraverse(root->right, out);
        } else out << "# ";
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }

public:
    string serialize(TreeNode* root) {
        ostringstream out;
        preTraverse(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};
