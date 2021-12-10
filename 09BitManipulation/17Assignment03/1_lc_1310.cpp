#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<int> preXor(n,0);
        preXor[0] = a[0];
        for (int i{1}; i<n; i++) preXor[i] = preXor[i-1]^a[i];
        int m = queries.size();
        vector<int> ans(m, 0);
        for (int q{0}; q<m; q++) {
            int i = queries[q][0], j = queries[q][1];
            if (i != 0) ans[q] = preXor[j]^preXor[i-1];
            else ans[q] = preXor[j];
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    Solution obj;
    vector<int> ans = obj.xorQueries(arr, queries);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}
