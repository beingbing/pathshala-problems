#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    char c;
    int f;
    struct Node* left;
    struct Node* right;

    Node(char ch, int freq, Node* l, Node* r) {
        c = ch;
        f = freq;
        left = l;
        right = r;
    }
};

struct Comp {
    bool operator() (Node* n1, Node* n2) {
        return n1->f > n2->f;
    }
};

class Solution {

    void getCodes(string code, Node* root, vector<string>& ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(code);
            return;
        }
        getCodes(code+'0', root->left, ans);
        getCodes(code+'1', root->right, ans);
    }

public:
    vector<string> huffmanCodes(string s, vector<int> f, int n) {
        priority_queue<Node*, vector<Node*>, Comp> pq;
        for (int i{0}; i<n; i++) pq.push(new Node(s[i], f[i], nullptr, nullptr));
        while (pq.size() > 1) {
            Node* n1 = pq.top();
            pq.pop();
            Node* n2 = pq.top();
            pq.pop();
            Node* n3 = new Node('.', n1->f + n2->f, n1, n2);
            pq.push(n3);
        }
        Node *root = pq.top();
        vector<string> ans;
        getCodes("", root, ans);
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++) cin >> f[i];
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
