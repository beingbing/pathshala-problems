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
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        for (string &ele : wordList) words.insert(ele);
        queue<GraphNode*> q;
        q.push(new GraphNode(beginWord));;
        vector<vector<string>> ans;
        if (!words.count(endWord)) return ans;
        int mn = words.size();
        while (!q.empty()) {
            GraphNode* x = q.front();
            q.pop();
            string temp = x->value;
            if (temp == endWord) {
                mn = min(mn, x->distance);
                if (x->transitions.size() == mn) ans.push_back(x->transitions);
            }
            for (int i{0}; i<temp.size(); i++) {
                char ch = temp[i];
                for (int j{0}; j<26; j++) {
                    char rep = j + 'a';
                    temp[i] = rep;
                    if (words.count(temp) > 0 && find(x->transitions.begin(), x->transitions.end(), temp) == x->transitions.end()) {
                        GraphNode* adj = new GraphNode(temp, x->distance + 1);
                        adj->transitions = x->transitions;
                        adj->transitions.push_back(temp);
                        q.push(adj);
                    }
                }
                temp[i] = ch;
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
