#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0);
        return res;        
    }
    
    void permute(vector<int>& nums, int itr){
        if(itr == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = itr; i < nums.size(); i++){
            swap(nums[itr], nums[i]);
            permute(nums, itr + 1);
            swap(nums[itr], nums[i]);
        }
    }
};