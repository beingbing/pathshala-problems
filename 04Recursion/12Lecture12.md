// ~~ subset of a set using bit maskig ~~
// mask: hidin some information
// bit masking is applicable when there are just two conditions to choose from.
// like here, one category is inclusion and other is exclusion

// here you are hiding the information that if bit is 0 i will not choose that element
// and if bit is 1 then i will choose that element

// tc = O(n*2^n)
#include <iostream>
#include <vector>
using namespace std;

class Solution { 
public:
    // using bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> ans(p);
        for (int i = 0; i < p; i++) // loop from 0 till 2^n-1
            for (int j = 0; j < n; j++) // check all the bits 1 by 1
                if ((i >> j) & 1) ans[i].push_back(nums[j]);
        return ans;
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