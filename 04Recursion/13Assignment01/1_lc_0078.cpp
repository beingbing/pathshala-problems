// tc = O(n*2^n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        if (i == nums.size()) {subs.push_back(sub);return;}
        sub.push_back(nums[i]);
        subsets(nums, i+1, sub, subs); // yes, include current element
        sub.pop_back();
        subsets(nums, i+1, sub, subs); // no, do not include current element
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
};

int main() {
    vector<int> nums = {1,3,2};
    Solution* obj = new Solution();
    vector<vector<int>> ans = obj->subsets(nums);
    for (auto rws : ans) {
        cout << "$: ";
        for (auto ele : rws) cout << ele << '\t';
        cout << endl;
    }
    return 0;
}