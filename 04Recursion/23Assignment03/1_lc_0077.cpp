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

import java.util.ArrayList;
import java.util.List;

public class CombinationsFinder {

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(1, n, k, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(int start, int n, int k, List<Integer> currentCombination, List<List<Integer>> result) {
        if (currentCombination.size() == k) {
            result.add(new ArrayList<>(currentCombination)); // Found valid combination
            return;
        }

        for (int i = start; i <= n; i++) {
            currentCombination.add(i);       // Choose element i
            backtrack(i + 1, n, k, currentCombination, result); // Explore further
            currentCombination.remove(currentCombination.size() - 1); // Un-choose element
        }
    }

    public static void main(String[] args) {
        CombinationsFinder solver = new CombinationsFinder();
        System.out.println(solver.combine(4, 2)); // Expected output: [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]
    }
}
