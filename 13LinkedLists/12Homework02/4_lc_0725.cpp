#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *cur = head, *tmp;
        int sz = 0;
        while (cur) {
            cur = cur->next;
            sz++;
        }
        int width = sz / k, rem = sz % k;
        vector<ListNode*> ans(k);
        cur = head;
        for (int i = 0; i < k && cur; ++i) {
            ans[i] = cur;
            for (int j = 1; j < width + (i < rem ? 1 : 0); ++j) cur = cur->next;
            tmp = cur->next;
            cur->next = nullptr;
            cur = tmp;
        }
        return ans;
    }
};

int main() {
    int n, x;
    cin >> n;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* tmp;
    while(n--) {
        cin >> x;
        ListNode* tmp = new ListNode(x);
        if (!head) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    cin >> x;
    Solution obj;
    vector<ListNode*> ans = obj.splitListToParts(head, x);
    for (auto &ele : ans) {
        while (ele) {
            cout << ele->val << " ";
            ele = ele->next;
        }
        cout << endl;
    }
    return 0;
}
