#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isStrPresent{false};
    int subTreeStrCnt{0};

    TrieNode() {
        for (int i{0}; i<26; i++) children[i] = nullptr;
        isStrPresent = false;
        subTreeStrCnt = 0;
    }
};

class Trie {
    TrieNode* root;

    void insert(TrieNode* cur, string& word, int pos) {
        cur->subTreeStrCnt++;
        if (pos == word.size()) {
            cur->isStrPresent = true;
            return;
        }
        if (!cur->children[word[pos]-'a']) cur->children[word[pos]-'a'] = new TrieNode();
        insert(cur->children[word[pos]-'a'], word, pos+1);
    }

    bool search(TrieNode* cur, string prfx, int pos) {
        if (!cur) return false;
        if (pos == prfx.size()) return cur->isStrPresent;
        return search(cur->children[prfx[pos]-'a'], prfx, pos+1);
    }

    bool startsWith(TrieNode *cur, string &prfx, int pos) {
        if (!cur) return false;
        if (pos == prfx.size()) return true;
        return startsWith(cur->children[prfx[pos]-'a'], prfx, pos+1);
    }

public:

    Trie(): root{new TrieNode()} {}
    
    void insert(string word) {
        insert(root, word, 0);
    }
    
    bool search(string word) {
        return search(root, word, 0);
    }
    
    bool startsWith(string prefix) {
        return startsWith(root, prefix, 0);
    }
};
