#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int sum, value;

    TrieNode(): sum{0}, value{0} {
        for (int i{0}; i<26; i++) children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

    void insert(TrieNode* cur, string& word, int pos, int& val) {
        cur->sum += val;
        if (pos == word.size()) {
            cur->value = val;
            return;
        }
        if (!cur->children[word[pos]-'a']) cur->children[word[pos]-'a'] = new TrieNode();
        insert(cur->children[word[pos]-'a'], word, pos+1, val);
    }

    void remove(TrieNode* cur, string& word, int pos, int& val) {
        cur->sum -= val;
        if (pos == word.size()) {
            cur->value = 0;
            return;
        }
        remove(cur->children[word[pos]-'a'], word, pos+1, val);
    }

    int getSum(TrieNode* cur, string& word, int pos) {
        if (!cur) return 0;
        if (pos == word.size()) return cur->sum;
        return getSum(cur->children[word[pos]-'a'], word, pos+1);
    }

    int search(TrieNode* cur, string prfx, int pos) {
        if (!cur) return 0;
        if (pos == prfx.size()) return cur->value;
        return search(cur->children[prfx[pos]-'a'], prfx, pos+1);
    }

public:

    Trie(): root{new TrieNode()} {}
    
    void insert(string word, int val) {
        insert(root, word, 0, val);
    }

    void remove(string word, int val) {
        remove(root, word, 0, val);
    }

    int getSum(string word) {
        return getSum(root, word, 0);
    }
    
    int search(string word) {
        return search(root, word, 0);
    }
};

class MapSum {
    Trie* trie;
public:
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        int curVal = trie->search(key);
        if (curVal) {
            trie->remove(key, curVal);
        }
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        return trie->getSum(prefix);
    }
};
