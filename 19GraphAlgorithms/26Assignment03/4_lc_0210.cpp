#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        for (auto &ele : prerequisites) {
            adj[ele[1]].push_back(ele[0]);
        }
        for (int i{0}; i<numCourses; i++) {
            for (int j{0}; j< adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }
        queue<int> possibleNodes;
        for (int i{0}; i<numCourses; i++) {
            if (indegree[i] == 0) possibleNodes.push(i);
        }
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
        return topologicalOrder.size() == numCourses ? topologicalOrder : vector<int>();
    }
};
