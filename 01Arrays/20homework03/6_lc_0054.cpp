#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int rs = 0, re = mat.size()-1;
        int cs = 0, ce = mat[0].size()-1;
        int i{0}, j{0};
        while ( rs <= re and cs <= ce) {
            for (j = cs; j<=ce; j++) ans.push_back(mat[rs][j]);
            for (i = rs+1; i<=re; i++) ans.push_back(mat[i][ce]);
            if (rs < re and cs < ce) {
                for (j = ce-1; j>cs; j--) ans.push_back(mat[re][j]);
                for (i = re; i>rs; i--) ans.push_back(mat[i][cs]);
            }
            rs++;
            ce--;
            re--;
            cs++;
        }
        return ans;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = obj->spiralOrder(mat);
    // for (auto ele : ans) cout << ele << endl;
    return 0;
}