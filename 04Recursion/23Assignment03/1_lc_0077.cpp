#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    
    void generate(vector<int>& combos, vector<int>& vals, int i, int j, int& k) {
        if (i < k and j == vals.size()) return;
        if (i == k) {ans.push_back(combos);return;}
        combos.push_back(vals[j]);
        generate(combos, vals, i+1, j+1, k);
        combos.pop_back();
        generate(combos, vals, i, j+1, k);
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combos, vals;
        for (int i{1}; i<=n; i++) vals.push_back(i);
        generate(combos, vals, 0, 0, k);
        return ans;
    }
};