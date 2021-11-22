#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](vector<int> x, vector<int> y) {
            return x[0]*x[0] + x[1]*x[1] < y[0]*y[0] + y[1]*y[1];
        });
        vector<vector<int>> ans;
        for (int i{0}; i<k; i++) ans.push_back(points[i]);
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
    Solution obj;
    vector<vector<int>> ans = obj.kClosest(points, k);
    for (auto rw : ans) {
        for (auto ele : rw) cout << ele << " ";
        cout << endl;
    }
    return 0;
}
