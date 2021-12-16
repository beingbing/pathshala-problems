#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    bool isValid( int i,  int j, int &n) {
        if (i >= 0 && i < n && j >= 0 && j < n) return true;
        return false;
    }

public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        vector<int> ans;
        if (n == 0) return ans;
        unordered_map<int,int> row, col, majorDia, minorDia;
        set<pair< int,  int>> illuminated;

        for (auto ele : lamps) {
            if (illuminated.find({ele[0], ele[1]}) == illuminated.end()) {
                row[ele[0]]++;
                col[ele[1]]++;
                majorDia[ele[0] - ele[1]]++;
                minorDia[ele[0] + ele[1]]++;
                illuminated.insert({ele[0], ele[1]});
            }
        }

        for (auto q : queries) {
            if (row[q[0]] > 0 || col[q[1]] > 0 || majorDia[q[0]-q[1]] > 0 || minorDia[q[0]+q[1]] > 0) ans.push_back(1);
            else ans.push_back(0);
            for ( int j = -1; j <= 1; j++) {
                for ( int k = -1; k <= 1; k++) {
                    if (isValid(q[0]+j, q[1]+k, n) && illuminated.find({q[0] + j, q[1] + k}) != illuminated.end()) {
                        illuminated.erase({q[0] + j, q[1] + k});
                        row[q[0] + j]--;
                        col[q[1] + k]--;
                        majorDia[q[0] + j - q[1] - k]--;
                        minorDia[q[0] + j + q[1] + k]--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> lamps = {{2,5},{4,2},{0,3},{0,5},{1,4},{4,2},{3,3},{1,0}}, queries = {{4,3},{3,1},{5,3},{0,5},{4,4},{3,3}};
    Solution obj;
    vector<int> ans = obj.gridIllumination(n, lamps, queries);
    for (auto ele : ans)
        cout << ele << " ";
    cout << endl;
    return 0;
}