#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode *next[2];
    int subTreeNumsCnt;
    TrieNode(): subTreeNumsCnt{0} {
        next[0] = nullptr;
        next[1] = nullptr;
    };
};

class Trie {
    TrieNode* root;

    void insert(TrieNode* cur, int& num, int j = 1 << 14) {
        cur->subTreeNumsCnt++;
        bool bt = num & j;
        if (!cur->next[bt]) cur->next[bt] = new TrieNode();
        if (j) insert(cur->next[bt], num, j/2);
    }

    int countLess(TrieNode* cur, int& num, int& limit, int j = 1 << 14) {
        if (!cur) return 0;
        bool idx = num & j;
        bool lim = limit & j;
        bool val = (num xor limit) & j;
        return ((lim && cur->next[idx]) ? cur->next[idx]->subTreeNumsCnt : 0) + countLess(cur->next[val], num, limit, j/2);
    }

public:

    Trie(): root{new TrieNode()} {}
    
    void insert(int num) {
        insert(root, num);
    }

    int countLess(int num, int limit) {
        return countLess(root, num, limit);
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int ans{0};
        Trie *trie = new Trie();
        for (auto &num : nums) {
            ans += trie->countLess(num, high+1) - trie->countLess(num, low);
            trie->insert(num);
        }
        return ans;
    }
};
