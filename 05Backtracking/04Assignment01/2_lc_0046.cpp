#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    
    void rightRotate(vector<int>& str, int i, int j) {
        int temp = str[j];
        for (auto idx{j}; idx > i; idx--) str[idx] = str[idx-1];
        str[i] = temp;
    }

    void leftRotate(vector<int>& str, int i, int j) {
        int temp = str[i];
        for (auto idx{i}; idx < j; idx++) str[idx] = str[idx+1];
        str[j] = temp;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0);
        return res;        
    }
    
    void permute(vector<int>& nums, int idx){
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        for (auto toSwapIdx{idx}; toSwapIdx < nums.size(); toSwapIdx++) {
            rightRotate(nums, idx, toSwapIdx); // do
            permute(nums, idx+1);              // recurse  
            leftRotate(nums, idx, toSwapIdx);  // undo
        }
    }
};