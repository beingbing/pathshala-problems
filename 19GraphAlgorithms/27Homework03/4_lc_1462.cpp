// floyd warshall algorithm
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjMat(numCourses, vector<int>(numCourses, INT_MAX/2));
        for (auto &ele : prerequisites) adjMat[ele[0]][ele[1]] = 1;
        for (int intermittentNode{0}; intermittentNode < numCourses; intermittentNode++) 
            for (int i{0}; i < numCourses; i++)
                for (int j{0}; j < numCourses; j++)
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][intermittentNode] + adjMat[intermittentNode][j]);
        vector<bool> ans;
        for (auto &q : queries)
            if (adjMat[q[0]][q[1]] != INT_MAX/2) ans.push_back(true);
            else ans.push_back(false);
        return ans;
    }
};
