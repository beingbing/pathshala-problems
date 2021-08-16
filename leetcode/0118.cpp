#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector< vector<int> > vec;
        vector<int> row(1, 1);
        vec.push_back(row);
        row = {};
        for (int i{1}; i<=n; i++) {
            for (int j{0}; j<=i; j++)
                if (j == 0) row.push_back(vec[i-1][j]);
                else if (j == i) row.push_back(vec[i-1][j-1]);
                else row.push_back(vec[i-1][j-1]+vec[i-1][j]);
            vec.push_back(row);
            row = {};
        }
        return vec;
    }
};

int main() {
    Solution* obj = new Solution();
    vector< vector<int> > ans = obj->generate(5);
    for (auto row : ans) {
        for (auto ele : row) cout << ele << '\t';
        cout << endl;
    }
    return 0;
}