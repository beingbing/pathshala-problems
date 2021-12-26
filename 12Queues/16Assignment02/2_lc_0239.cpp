#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {

    void insertAtBack(deque<int>& d, int& idx, vector<int>& nums) {
        while (!d.empty() && nums[idx] >= nums[d.back()]) d.pop_back();
        d.push_back(idx);
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> d;
        for (int i{0}; i<k; i++) insertAtBack(d, i, nums);
        for (int i{k}; i<n; i++) {
            ans.push_back(nums[d.front()]);
            if (d.front() == i-k) d.pop_front();
            insertAtBack(d, i, nums);
        }
        ans.push_back(nums[d.front()]);
        return ans;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(nums, k);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}
