#include <iostream>
#include <unordered_set>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

bool checkPairSum(struct ListNode *head, int sum) {
    unordered_set<int> s;
    ListNode *p = head;
    while (p) {
        int curr = p->data;
        if (s.find(sum - curr) != s.end()) {
            cout << curr << " " << sum - curr;
            return true;
        }
        s.insert(p->data);
        p = p->next;
    }
    return false;
}

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
    bool res = checkPairSum(head, x);
    if (res == false) cout << "NO PAIR EXIST";
    cout << endl;
    return 0;
}
