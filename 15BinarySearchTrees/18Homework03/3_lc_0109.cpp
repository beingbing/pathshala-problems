struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr ;
        return constructTree(head, nullptr);
    }
    
    TreeNode *constructTree(ListNode *head, ListNode *tail) {
        if (!head || head == tail) return nullptr;
        ListNode *fst = head;
        ListNode *slw = head;
        while (fst->next != tail && fst->next->next != tail) {
            slw = slw->next;
            fst = fst->next->next;
        }
        TreeNode *rut = new TreeNode(slw->val);
        rut->left = constructTree(head, slw);
        rut->right = constructTree(slw->next, tail);
        return rut;
    }
};
