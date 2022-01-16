#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1000000007

struct NODE {
    int data;
    struct NODE *left;
    struct NODE *right;
    NODE(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

NODE *root = NULL;

NODE *insert(int num, NODE *root) {
    if (root == NULL) {
        NODE *temp = new NODE(num);
        return temp;
    } else if (root->data >= num) root->left = insert(num, root->left);
    else root->right = insert(num, root->right);
    return root;
}

int ans{-1};

void checkPthAncestor(vector<int>& stk, int target) {
    while (target > 1 && !stk.empty()) stk.pop_back(), target--;
    if (target == 1 && !stk.empty()) ans = stk.back();
    if (target > 1 && stk.empty()) ans = -1;
}

NODE* lowestCommonAncestor(NODE* root, int& p, int& q, vector<int>& stk, int& target) {
        if (!root) return NULL;
        stk.push_back(root->data);
        if (root->data == p || root->data == q) {
            checkPthAncestor(stk, target);
            return root;
        }
        int mx = max(p, q);
        int mn = min(p, q);
        if (root->data > mn && root->data < mx) {
            checkPthAncestor(stk, target);
            return root;
        }
        if (root->data < mn && root->data < mx) return lowestCommonAncestor(root->right, p, q, stk, target);
        return lowestCommonAncestor(root->left, p, q, stk, target);
    }

int pthCommonAncestor(int x, int y, NODE *root, int target, vector<int> &vec) {
    ans = -1;
    lowestCommonAncestor(root, x, y, vec, target);
    return ans;
}

int main() {
    int t, n, num, x, y, temp, p;
    scanf("%d", &t);
    while (t--) {
        vector<int> vec;
        NODE *root = NULL;
        vec.clear();
        scanf("%d %d", &n, &p);
        while (n--) {
            scanf("%d", &num);
            root = insert(num, root);
        }
        scanf("%d%d", &x, &y);
        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }
        printf("%d\n", pthCommonAncestor(x, y, root, p, vec));
    }
    return 0;
}
