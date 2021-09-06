#include <vector>
#include <climits>
#include <string>
using namespace std;

class TrieNode {
    TrieNode* next[26];
    bool isPresent{false};
    int prefixCnt{0};

public:
    TrieNode() {
        for (int i{0}; i<26; i++) next[i] = NULL;
        isPresent = false;
        prefixCnt = 0;
    }
};

class trie {
private:
    TrieNode* root;
public:
    trie() {
        root = new TrieNode();
    }

    TrieNode* insertWord(TrieNode* root, string str, int pos) {
        if (pos > str.size()) return root;
        if (!root) root = new TrieNode();
        root->prefixCnt++;
        if (pos == str.size()) root->isPresent = true;
        else root->next[str[pos]-'a'] = insertWord(root->next[str[pos]-'a'], str, pos+1);
        return root;
    }

    void insert(string word) {
        root = insertWord(root, word, 0);
    }

    bool searchWord(TrieNode* root, string str, int pos) {
        if (!root) return false;
        if (pos == str.size()) return root->isPresent;
        return searchWord(root->next[str[pos]-'a'], str, pos+1);
    }

    bool search(string word) {
        return searchWord(root, word, 0);
    }

    void deletion(TrieNode* root, string str, int pos) {
        if (!root) return;
        bool found = false;
        if (pos == str.size()) {
            if (root->isPresent) {
                found = true;
                root->strCnt--;
            }
            return;
        }
        deletion(root->next[str[pos]-'a'], str, pos+1);
        if (found) root->strCnt--;
        if (root->next[str[pos]-'a']->strCnt == 0) {
            TrieNode* temp = root->next[str[pos]-'a'];
            root->next[str[pos]-'a'] = NULL;
            delete(temp);
        }
    }
};
