#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int subTreeStrCnt{0};

    TrieNode() {
        for (int i{0}; i<26; i++) children[i] = nullptr;
        subTreeStrCnt = 0;
    }
};

class Trie {
    TrieNode* root;

    void insert(TrieNode* cur, string& word, int pos) {
        cur->subTreeStrCnt++;
        if (pos == word.size()) return;
        if (!cur->children[word[pos]-'a']) cur->children[word[pos]-'a'] = new TrieNode();
        insert(cur->children[word[pos]-'a'], word, pos+1);
    }

    int startsWith(TrieNode *cur, string &prfx, int pos) {
        if (!cur) return 0;
        if (pos == prfx.size()) return cur->subTreeStrCnt;
        return startsWith(cur->children[prfx[pos]-'a'], prfx, pos+1);
    }

public:

    Trie(): root{new TrieNode()} {}
    
    void insert(string word) {
        insert(root, word, 0);
    }
    
    int startsWith(string prefix) {
        return startsWith(root, prefix, 0);
    }
};

class Solution {
public:
    vector<int> prefixCount(int n, int q, string li[], string query[]) {
        Trie* trie = new Trie();
        for (int i{0}; i<n; i++) trie->insert(li[i]);
        vector<int> ans;
        for (int i{0}; i<q; i++) ans.push_back(trie->startsWith(query[i]));
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int Q, N, i = 0, x;
        cin >> N;
        string s;
        string li[N];
        for (int i = 0; i < N; i++) cin >> li[i];
        cin >> Q;
        x = Q;
        string query[Q];
        while (Q--) {
            cin >> s;
            query[i++] = s;
        }
        Solution ob;
        vector<int> ans = ob.prefixCount(N, x, li, query);
        for (auto i : ans) cout << i << "\n";
    }
    return 0;
}
