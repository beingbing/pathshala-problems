#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i{0}; i<n; i++) {
            if (i>0 and nums[i] == nums[i-1]) continue;
            else {
                for (int j{i+1}; j<n; j++) {
                    if (j>i+1 and nums[j] == nums[j-1]) continue;
                    else {
                        int remSum = target - (nums[i]+nums[j]);
                        int p1 = j+1, p2 = n-1;
                        while (p1 < p2) {
                            if (nums[p1]+nums[p2] < remSum) p1++;
                            else if (nums[p1]+nums[p2] > remSum) p2--;
                            else {
                                ans.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                                if (nums[p1] == nums[p2]) break;
                                else {
                                    int x = nums[p1], y = nums[p2];
                                    while (nums[p1] == x) p1++;
                                    while (nums[p2] == y) p2--;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution obj;
    vector<vector<int>> ans = obj.fourSum(nums, target);
    for (auto rw : ans) {
        for (auto ele : rw) cout << ele << " ";
        cout << endl; 
    }
    return 0;
}