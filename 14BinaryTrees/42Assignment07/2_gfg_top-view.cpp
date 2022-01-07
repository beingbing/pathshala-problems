#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution {
    vector<int> ans;

public:
    vector<int> topView(Node *root) {
        if (!root) return ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        unordered_map<int, int> mp;
        int mx = INT_MIN, mn = INT_MAX;
        while (!q.empty()) {
            pair<Node*, int> p = q.front();
            q.pop();
            mx = max(mx, p.second);
            mn = min(mn, p.second);
            if (mp.find(p.second) == mp.end()) mp[p.second] = p.first->data;
            if (p.first->left) q.push({p.first->left, p.second - 1});
            if (p.first->right) q.push({p.first->right, p.second + 1});
        }
        for (int i{mn}; i<=mx; i++) ans.push_back(mp[i]);
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    return 0;
}
