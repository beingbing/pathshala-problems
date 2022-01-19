#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode *next[2];
    int value;
    TrieNode(): value{0} {
        next[0] = nullptr;
        next[1] = nullptr;
    };
};

class Trie {
    TrieNode* root;

    void insert(TrieNode* cur, int& val) {
        for (int i{31}; i >= 0; i--) {
            bool idx = val & (1 << i);
            if (!cur->next[idx]) cur->next[idx] = new TrieNode();
            cur = cur->next[idx];
        }
        cur->value = val;
    }

    int query(TrieNode *cur, int num) {
        for (int i{31}; i >= 0; i--) {
            bool idx = (num  & (1 << i));
            if (cur->next[1-idx]) cur = cur->next[1-idx];
            else if (cur->next[idx]) cur = cur->next[idx];
        }
        return num ^ (cur->value);
    }

public:
    Trie(): root{new TrieNode()} {}

    void insert(int num) {
        insert(root, num);
    }

    int query(int num, int& x) {
        return query(root, num xor x);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        for (int i{0}; i<n; i++) cin >> nums[i];
        Trie *trie = new Trie();
        trie->insert(0);
        int ans = INT_MIN, preXor = 0;
        for (int i{0}; i < n; i++) {
            preXor = preXor ^ nums[i];
            trie->insert(preXor);
            ans = max(ans, trie->query(preXor, x));
        }
        cout << (ans ^ x) << endl;
    }
    return 0;
}
