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

    void findUniquePrefix(TrieNode* cur, string &word, int pos, string &ans) {
        if (cur->subTreeStrCnt == 1) {
            ans = word.substr(0, pos);
            return;
        }
        findUniquePrefix(cur->children[word[pos]-'a'], word, pos+1, ans);
    }

public:

    Trie(): root{new TrieNode()} {}
    
    void insert(string word) {
        insert(root, word, 0);
    }
    
    string uniquePrefix(string word) {
        string ans;
        findUniquePrefix(root, word, 0, ans);
        return ans;
    }
};

class Solution {
public:
    vector<string> findPrefixes(string a[], int n) {
        Trie* trie = new Trie();
        for (int i{0}; i<n; i++) trie->insert(a[i]);
        vector<string> ans;
        for (int i{0}; i<n; i++) ans.push_back(trie->uniquePrefix(a[i]));
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
