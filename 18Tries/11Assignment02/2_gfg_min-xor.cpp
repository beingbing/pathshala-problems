#include <iostream>
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

    int getMin(TrieNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1);
            cout << index << endl;
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

    int getMin(int num) {
        return getMin(root, num);
    }
};

class Solution {
public:
    int minxorpair(int n, int a[]) {
        Trie *trie = new Trie();
        trie->insert(a[0]);
        int mn = INT_MAX;
        for (int i{1}; i<n; i++) {
            mn = min(mn, trie->getMin(a[i]));
            trie->insert(a[i]);
        }
        return mn;
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
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0;
}

/*

class Solution {
public:
    struct Node {
        Node* left;//left will represent that the corresponding bit has a value=0;
        Node* right;//right will represent that the corresponding bit has a value=1;
        int num;
    };
    Node *createNode() {
        Node *tmp = new Node;
        tmp->left = tmp->right = NULL;
        tmp->num = -1;
        return tmp;
    }
    void insert(Node* root, int key)
    {
        Node* temp = root;
        for (int i = 17; i >= 0; i--) {
            bool current_bit = (key & (1 << i));
 
            if (!current_bit) {
                if (!temp -> left) {
                    temp -> left = createNode();
                }
 
                temp = temp -> left;
            }
            else {
                if (!temp -> right) {
                    temp -> right = createNode();
                }
 
                temp = temp -> right;
            }
        }
        temp->num = key;
    }
    int search(Node* root, int key) {
        Node* temp = root;
 
        for (int i = 17; i >= 0; i--) {
            bool current_bit = (key & (1 << i));
 
            if (!current_bit) {
                if (temp -> left) temp = temp -> left;
                else temp = temp -> right;
            }
            else {
                if (temp -> right) temp = temp -> right;
                else temp = temp -> left;
            }
        }
 
        return key ^ temp->num;
    }
    int minxorpair(int N, int arr[]) {
        //code here
        Node* root = createNode();
        int ans = INT_MAX;
        insert(root, arr[0]);
        for (int i = 1; i < N; i++) {
            ans = min( ans, search(root, arr[i]));
            insert(root, arr[i]);
        }
        return ans;
    }
};

*/