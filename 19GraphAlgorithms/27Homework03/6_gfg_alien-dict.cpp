#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {

    vector<int> topoSort(int n, vector<vector<int>> &adj) {
        vector<int> indegree(n, 0);
        for (int i{0}; i<n; i++) for (int j{0}; j< adj[i].size(); j++) indegree[adj[i][j]]++;
        queue<int> possibleNodes;
        for (int i{0}; i<n; i++) if (indegree[i] == 0) possibleNodes.push(i);
        vector<int> topologicalOrder;
        while (!possibleNodes.empty()) {
            int x = possibleNodes.front();
            possibleNodes.pop();
            topologicalOrder.push_back(x);
            for (int j{0}; j<adj[x].size(); j++) {
                indegree[adj[x][j]]--;
                if(indegree[adj[x][j]] == 0) possibleNodes.push(adj[x][j]);
            }
        }
        return topologicalOrder;
    }

public:
    string findOrder(string dict[], int n, int k) {
        vector<vector<int>> adjList(k);
        for (int i{1}; i<n; i++) {
            string frst = dict[i-1];
            string scnd = dict[i];
            int sz = min(frst.size(), scnd.size());
            for (int j{0}; j<sz; j++) {
                if (frst[j] == scnd[j]) continue;
                adjList[frst[j] - 'a'].push_back(scnd[j] - 'a');
                break;
            }
        }
        vector<int> strCand = topoSort(k, adjList);
        string ans, tmp;
        for (auto &ele : strCand) {
            tmp = ele + 'a';
            ans += tmp;
        }
        return ans;
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }
    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();
    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];
        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);
        bool f = true;
        for (int i = 0; i < N; i++) if (dict[i] != temp[i]) f = false;
        if (f) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
