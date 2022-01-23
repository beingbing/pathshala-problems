#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class GraphNode {
public:
    string value;
    int distance;
    vector<string> transitions;
    GraphNode(string& val): value{val}, distance{1}, transitions{{val}} {} 
    GraphNode(string& val, int dist): value{val}, distance{dist} {} 
};

class Solution {

    bool oneStep(string &a, string &b) {
        if (a.size() != b.size()) return false;
        int cnt = 0;
        for (int i{0}; i<a.size(); i++) if (a[i] != b[i]) cnt++;
        return cnt == 1;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);
        int n = wordList.size();
        unordered_map<string, int> nodes;
        for (int i{0}; i < n; i++) nodes[wordList[i]] = i;
        vector<vector<int>> adj;
        for (int i{0}; i<n; i++) adj.push_back({});
        for (int i{0}; i<n; i++) {
            for (int j{i+1}; j<n; j++) {
                if (oneStep(wordList[i], wordList[j])) {
                    adj[nodes[wordList[i]]].push_back(nodes[wordList[j]]);
                    adj[nodes[wordList[j]]].push_back(nodes[wordList[i]]);
                }
            }
        }
        queue<GraphNode*> q;
        q.push(new GraphNode(beginWord));
        vector<vector<string>> ans;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return ans;
        int mn = n+1;
        while (!q.empty()) {
            GraphNode* x = q.front();
            q.pop();
            string tmp = x->value;
            if (tmp == endWord) {
                mn = min(mn, x->distance);
                if (x->transitions.size() == mn) ans.push_back(x->transitions);
            }
            for (int i{0}; i<adj[nodes[tmp]].size(); i++) {
                string str = wordList[adj[nodes[tmp]][i]];
                if (find(x->transitions.begin(), x->transitions.end(), str) != x->transitions.end()) continue;
                GraphNode* adj = new GraphNode(str, x->distance + 1);
                adj->transitions = x->transitions;
                adj->transitions.push_back(str);
                q.push(adj);
            }
        }
        return ans;
    }
};

int main() {
    string begnWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution obj;
    vector<vector<string>> ans = obj.findLadders(begnWord, endWord, wordList);
    cout << " ==== ans ==== " << endl; 
    for (auto &rw : ans) {
        for (auto &ele : rw) cout << ele << " ";
        cout << endl;
    }
    return 0;
}
