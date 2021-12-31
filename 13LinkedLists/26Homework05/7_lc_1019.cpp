#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> stk;
        for (ListNode* node = head; node; node = node->next) {
            while (stk.size() && res[stk.top()] < node->val) {
                res[stk.top()] = node->val;
                stk.pop();
            }
            stk.push(res.size());
            res.push_back(node->val);
        }
        while (!stk.empty()) res[stk.top()] = 0, stk.pop();
        return res;
    }
};
