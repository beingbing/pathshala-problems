#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode *next[2];
    TrieNode() {
        next[0] = nullptr;
        next[1] = nullptr;
    };
};

class Trie {
    TrieNode* root;

    int getMax(TrieNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res |= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }

public:

    Trie(): root{new TrieNode()} {}
    
    void insert(int num) {
        TrieNode *cur = root;
        for (int j{31}; j >= 0; j--) {
            int index = ((num >> j) & 1);
            if (cur->next[index] ==  NULL)
                cur->next[index] = new TrieNode();
            cur = cur->next[index];
        }
    }

    int getMax(int num) {
        return getMax(root, num);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        Trie *trie = new Trie();
        for (auto &ele : nums) trie->insert(ele);
        int mx = INT_MIN;
        for (auto &ele : nums) mx = max(mx, trie->getMax(ele));
        return mx;
    }
};
