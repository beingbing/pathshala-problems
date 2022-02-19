// ~~ lexicographical subsets printing ~~
// extension of leetcode 0078

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> subs;

    void subsets(vector<int> &nums, int i, vector<int> &sub) {
        subs.push_back(sub); // not including any array element beyond current element
        // if you have considered the smallest number once, then do not consider it again
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        subsets(nums, 0, sub);
        return subs;
    }
};

int main() {
    vector<int> nums = {1, 3, 2};
    Solution *obj = new Solution();
    vector<vector<int>> ans = obj->subsets(nums);
    for (auto rws : ans) {
        cout << "$: ";
        for (auto ele : rws) cout << ele << '\t';
        cout << endl;
    }
    return 0;
}

// TC = O(2^n)
// more optimal then the previous one
