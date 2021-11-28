#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i= 0, n = nums.size();
        for (;i < n; i++) if (nums[i] >= 0) break;
        int j = i-1;
        vector<int> ans;
        while (j >= 0 and i < n) {
            if (nums[i]*nums[i] <= nums[j]*nums[j]) {
                ans.push_back(nums[i]*nums[i]);
                i++;
            } else {
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        while (j >= 0) ans.push_back(nums[j]*nums[j]), j--;
        while (i < n) ans.push_back(nums[i]*nums[i]), i++;
        return ans;
    }
};

int main() {
    vector<int> nums = {-4,-1,0,3,10};
    Solution obj;
    nums = obj.sortedSquares(nums);
    for (auto ele : nums) cout << ele << " ";
    cout << endl;
    return 0;
}
