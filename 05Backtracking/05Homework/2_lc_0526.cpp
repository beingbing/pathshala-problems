#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
    vector<vector<int>> ans;
    
    void permute(vector<int>& vec, int idx) {
        if (idx == vec.size()) {
            ans.push_back(vec);
            return;
        }
        for (int toIdx{idx}; toIdx < vec.size(); toIdx++) {
            if (vec[toIdx]%(idx+1) == 0 || (idx+1)%vec[toIdx] == 0) {
                swap(vec[idx], vec[toIdx]);
                permute(vec, idx+1);
                swap(vec[idx], vec[toIdx]);
            }
        }
    }
    
public:
    int countArrangement(int n) {
        vector<int> vec;
        for (int i{1}; i<=n; i++) vec.push_back(i);
        permute(vec, 0);
        return ans.size();
    }
};