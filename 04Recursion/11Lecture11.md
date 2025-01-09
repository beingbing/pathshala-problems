~~ all subsets of a set ~~

set: a collection of distinct/unique elements

Problem: Given an integer array 'nums' of unique elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets. You can return the solution in any order.

Solution:
think in the manner of inclusion-exclusion when you have to generate all the Combinations. Either have that element, or not have it.

so it will have a binary tree with one side for Inclusion and other with Exclusion

    a   b   c   d   e

    2 * 2 * 2 * 2 * 2  number of choices

by rule of product, we have 2^n results

code -
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

complexity -
recursion tree diagram  will have at every level 2^i leaves, and n (size of subset) will be the height of recursion tree. Total number of function call will be equal to the total number of nodes of tree, which will be the sum of nodes at each level, which will be -
1 + 2 + 4 + 8 + ... + 2^(n-2) + 2^(n-1) + 2^n = 2^(n+1) - 1
so, total invocation calls are 2^n, but at each leave node, printing of complete subset will also happen which can be of size n for each leaf node.
thus, tc = O(n*2^n)

Think of its iterative solution as well
