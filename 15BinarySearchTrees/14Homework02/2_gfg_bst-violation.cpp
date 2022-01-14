// tried doing inversion count with merge sort, getting error.
// problem not important, just there to irritate people. Nothing new can be learned.
#include <iostream>
#include <vector>
using namespace std;
#define ll int
#define MOD 1000000007

int indx, ans;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

int pairsViolatingBST(Node *root, int n);

void insert(Node *root, int a, int b, char ch);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        indx = 0;
        ans = 0;
        Node *root = NULL;
        for (int j = 0; j < n; j++) {
            int a, b;
            char ch;
            cin >> a >> b >> ch;
            if (root == NULL) {
                root = new Node(a);
                switch (ch) {
                case 'L':
                    root->left = new Node(b);
                    break;
                case 'R':
                    root->right = new Node(b);
                    break;
                }
            } else insert(root, a, b, ch);
        }
        cout << pairsViolatingBST(root, n) << "\n";
    }
    return 0;
}

void insert(Node *root, int a, int b, char ch) {
    if (root == NULL) return;
    if (root->data == a) {
        switch (ch) {
        case 'L':
            root->left = new Node(b);
            break;
        case 'R':
            root->right = new Node(b);
            break;
        }
    } else {
        insert(root->left, a, b, ch);
        insert(root->right, a, b, ch);
    }
}

void store(Node* root, vector<int>& vals) {
    if (!root) return;
    store(root->left, vals);
    vals.push_back(root->data);
    store(root->right, vals);
}

int pairsViolatingBST(Node *root, int n) {
    vector<int> vals;
    store(root, vals);
    int cnt{0};
    for (int i{0}; i < vals.size(); i++)
        for(int j{i+1}; j < vals.size(); j++)
            if(vals[i] >= vals[j]) cnt++;
    return cnt;
}
