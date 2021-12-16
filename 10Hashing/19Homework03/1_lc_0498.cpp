#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int m = mat.size(), n = mat[0].size();
        for (int i{0}; i<m; i++) for (int j{0}; j<n; j++) mp[i+j].push_back(mat[i][j]);
        vector<int> ans;
        for (auto ele : mp)
            if (ele.first % 2 == 0) for (auto it = ele.second.rbegin(); it != ele.second.rend(); it++) ans.push_back(*it);
            else for (auto it = ele.second.begin(); it != ele.second.end(); it++) ans.push_back(*it);
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution obj;
    vector<int> ans = obj.findDiagonalOrder(mat);
    for (auto ele : ans) cout << ele << " ";
    cout << endl;
    return 0;
}