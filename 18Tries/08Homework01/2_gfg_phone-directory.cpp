#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    vector<int> indices;

    TrieNode() {
        for (int i{0}; i<26; i++) children[i] = nullptr;
    }
};

class Trie {
    TrieNode *root;

    void insert(TrieNode *cur, string &word, int pos, int &idx) {
        if (pos == word.size()) return;
        if (!cur->children[word[pos]-'a']) cur->children[word[pos]-'a'] = new TrieNode();
        cur->children[word[pos]-'a']->indices.push_back(idx);
        insert(cur->children[word[pos]-'a'], word, pos+1, idx);
    }

    void getContacts(TrieNode *cur, string& prfx, int pos, vector<vector<string>> &res, vector<string> &directory) {
        if (pos == prfx.size() || !cur->children[prfx[pos]-'a']) return;
        vector<string> directories;
        for (int ele : cur->children[prfx[pos]-'a']->indices) directories.push_back(directory[ele]);
        res.push_back(directories);
        getContacts(cur->children[prfx[pos]-'a'], prfx, pos+1, res, directory);
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word, int idx) {
        insert(root, word, 0, idx);
    }

    void getContacts(string prfx, vector<vector<string>> &res, vector<string> &directory) {
        getContacts(root, prfx, 0, res, directory);
    }
};

class Solution {

    vector<string> unqContacts(string a[], int n) {
        set<string> st(a, a + n);
        return vector<string>(st.begin(), st.end());
    }

public:
    vector<vector<string>> displayContacts(int n, string contact[], string prfx) {
        vector<string> directory = unqContacts(contact, n);
        n = directory.size();
        Trie trie;
        for (int i = 0; i < n; i++) trie.insert(directory[i], i);
        vector<vector<string>> res;
        trie.getContacts(prfx, res, directory);
        while (res.size() < prfx.size()) res.push_back({"0"});
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++) cin >> contact[i];
        cin >> s;
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++) {
            for (auto u : ans[i]) cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}
