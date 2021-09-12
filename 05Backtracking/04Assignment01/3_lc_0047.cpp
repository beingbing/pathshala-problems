#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    
    void permute(vector<int>& nums, int idx) {
        if (idx == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        vector<int> freq(21, 0);
        for (int toSwapIdx{idx}; toSwapIdx < nums.size(); toSwapIdx++) {
            if (freq[nums[toSwapIdx]+10] == 0) {
                swap(nums[idx], nums[toSwapIdx]);
                permute(nums, idx+1);
                swap(nums[idx], nums[toSwapIdx]);
                freq[nums[toSwapIdx]+10]++;
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums, 0);
        return res;
    }
};