#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], freq = 1, n = nums.size();
        for (int i{1}; i<n; i++) {
            if (ele == nums[i]) freq++;
            else freq--;
            if (freq == 0) {ele = nums[i];freq = 1;}
        }
        return ele;
    }
};