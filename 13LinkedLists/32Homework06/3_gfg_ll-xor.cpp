#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> printList(struct Node *head);

int main() {
    int t;
    cin >> t;
    while (t--) {
        struct Node *head = NULL;
        int n, tmp;
        cin >> n;
        while (n--) {
            cin >> tmp;
            head = insert(head, tmp);
        }
        vector<int> vec = printList(head);
        for (int x : vec) cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) cout << vec[i] << " ";
        cout << "\n";
    }
    return (0);
}

struct Node *insert(struct Node *head, int data) {
    Node* tmp = new Node(data);
	tmp->npx = XOR(NULL, head);
	if (head) head->npx = XOR(tmp, head->npx);
	head = tmp;
	return head;
}

vector<int> printList(struct Node *head) {
    vector<int> vec;
	Node *cur = head, *prv = NULL, *nxt;
	while (cur){
		vec.push_back(cur->data);
		nxt = XOR(prv, cur->npx);
		prv = cur;
		cur = nxt;
	}
	return vec;
}
