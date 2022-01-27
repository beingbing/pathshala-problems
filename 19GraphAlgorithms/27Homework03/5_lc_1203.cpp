#include <queue>
#include <vector>
using namespace std;

class Solution {

    vector<int> topoSort(int n, vector<vector<int>> adj, bool& hasCycle) {
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
        if (topologicalOrder.size() != n) hasCycle = true;
        return topologicalOrder;
    }

public:
    vector<int> sortItems(int itmCnt, int grpCnt, vector<int>& grpId, vector<vector<int>>& ItmInvertedAdjList) {
        for (int i = 0; i < itmCnt; ++i) if(grpId[i] == -1) grpId[i] = grpCnt++;
        vector<vector<int>> grpAdjList(grpCnt);
        for (int i=0; i<itmCnt; ++i){
            for (int j : ItmInvertedAdjList[i]){
                if (grpId[i] == grpId[j]) continue;
                grpAdjList[grpId[j]].push_back(grpId[i]);
            }
        }
        vector<vector<int>> itmAdjList(itmCnt);
        for (int i{0}; i < itmCnt; i++) for (int &ele : ItmInvertedAdjList[i]) itmAdjList[ele].push_back(i);
        bool hasCycle = false;
        vector<int> itemOrder = topoSort(itmCnt, itmAdjList, hasCycle);
        if (hasCycle) return {};
        vector<int> groupOrder = topoSort(grpCnt, grpAdjList, hasCycle);
        if (hasCycle) return {};
        vector<vector<int>> group2item(grpCnt);
        for(auto item : itemOrder){
            group2item[grpId[item]].push_back(item);
        }
        vector<int> ans;
        for(int group_id : groupOrder) {
            for(int item : group2item[group_id]) {
                ans.push_back(item);
            }
        }
        return ans;
    }
};
