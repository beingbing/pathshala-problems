// count number of distinct subsets of an array which has sum equal to given target

// lexicographical subsets printing
// extension of leetcode 0078

#include <iostream>
#include <vector>
using namespace std;

class Solution {

    vector<vector<int>> subs;
    
    void subsets(vector<int>& nums, int i, vector<int>& sub, int sum, int& target) {
        if (sum == target) subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, sum+nums[j], target);
            sub.pop_back();
        }
    }

    void subsets2(vector<int>& nums, int i, vector<int>& sub, int sum, int& target) {
        if (i == nums.size()) {
            if (sum == target) subs.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        subsets2(nums, i+1, sub, sum+nums[i], target); // yes, include current element
        sub.pop_back();
        subsets2(nums, i+1, sub, sum, target); // no, do not include current element
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        subsets2(nums, 0, sub, 0, target);
        return subs;
    }
};

int main() {
    vector<int> nums = {1,3,2,4};
    Solution* obj = new Solution();
    vector<vector<int>> ans = obj->subsets(nums, 4);
    for (auto rws : ans) {
        cout << "$: ";
        for (auto ele : rws) cout << ele << '\t';
        cout << endl;
    }
    return 0;
}