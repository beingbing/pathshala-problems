#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    
    void generate(vector<int> combos, vector<int>& candidates, int track, int target) {
        if (track == candidates.size()) return;
        if (target < 0) return;
        if (target == 0) {ans.push_back(combos);return;}
        combos.push_back(candidates[track]);
        generate(combos, candidates, track, target-candidates[track]);
        combos.pop_back();
        generate(combos, candidates, track+1, target);
    }

    void generate2(vector<int> combos, vector<int>& candidates, int track, int target) {
        if (target < 0) return;
        if (target == 0) {ans.push_back(combos);return;}
        for (int i{track}; i < candidates.size() and target > 0; i++) {
            combos.push_back(candidates[i]);
            generate(combos, candidates, i, target-candidates[i]);
            combos.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combos;
        generate(combos, candidates, 0, target);
        return ans;    
    }
};