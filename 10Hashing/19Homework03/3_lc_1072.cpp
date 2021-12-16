// check relative ordering of remaining elements in a row with respect to its first element.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        for (auto &row : matrix) {
            int x = row[0];
            string str;
            for (auto &ele : row)
                if (ele == x) str += '1';
                else str += '0';
            mp[str]++;
        }
        int ans{INT_MIN};
        for (auto &ele : mp) ans = max(ele.second, ans);
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{0,0,0},{0,0,1},{1,1,0}};
    Solution obj;
    cout << obj.maxEqualRowsAfterFlips(matrix) << endl;
    return 0;
}
