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

    int query(int num) {
        return query(root, num);
    }
};

class Solution{   
public:
    int maxSubarrayXOR(int n, int a[]){    
        Trie *trie = new Trie();
        trie->insert(0);
        int ans = INT_MIN, preXor = 0;
        for (int i{0}; i < n; i++) {
            preXor = preXor ^ a[i];
            trie->insert(preXor);
            ans = max(ans, trie->query(preXor));
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, X;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0;
}
