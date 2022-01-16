#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isStrPresent{false};

    TrieNode() {
        for (int i{0}; i<26; i++) children[i] = nullptr;
        isStrPresent = false;
    }
};

class Trie {
    TrieNode* root;

    void insert(TrieNode* cur, string& word, int pos) {
        if (pos == word.size()) {
            cur->isStrPresent = true;
            return;
        }
        if (!cur->children[word[pos]-'a']) cur->children[word[pos]-'a'] = new TrieNode();
        insert(cur->children[word[pos]-'a'], word, pos+1);
    }

    void findRoot(TrieNode* cur, string &word, int pos, string &ans) {
        if (!cur || pos == word.size()) {
            ans = word;
            return;
        }
        if (cur->isStrPresent) {
            ans = word.substr(0, pos);
            return;
        }
        findRoot(cur->children[word[pos]-'a'], word, pos+1, ans);
    }

public:

    Trie(): root{new TrieNode()} {}
    
    void insert(string word) {
        insert(root, word, 0);
    }
    
    string rootReplace(string word) {
        string ans;
        findRoot(root, word, 0, ans);
        return ans;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for (string &root: dictionary) trie->insert(root);
        istringstream ss(sentence);
        string token, ans;
        while(getline(ss, token, ' ')) {
            if (ans.size() > 0) ans += " ";
            ans += trie->rootReplace(token);
        }
        return ans;
    }
};
