#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    
    void generate(vector<int>& combos, vector<int>& vals, long target, int i, int j, int& k) {
        if (i > k || j > vals.size()) return;
        if (i < k and j == vals.size()) return;
        if (i == k and target == 0) {ans.push_back(combos);return;}
        combos.push_back(vals[j]);
        generate(combos, vals, target-vals[j], i+1, j+1, k);
        combos.pop_back();
        generate(combos, vals, target, i, j+1, k);
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> combos, vals;
        for (int i{1}; i<=9; i++) vals.push_back(i);
        generate(combos, vals, target, 0, 0, k);
        return ans;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<vector<int>> ans = obj->combinationSum3(3, 9);
    for (auto rw : ans) {
        for (auto ele : rw) cout << ele << '\t';
        cout << endl;
    }
    return 0;
}