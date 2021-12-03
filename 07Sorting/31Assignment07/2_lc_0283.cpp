#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, cnt = 0, n = nums.size();
        while (i < n) {
            if (nums[i] != 0) {
                swap(nums[cnt], nums[i]);
                cnt++;
            }
            i++;
        }
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution obj;
    obj.moveZeroes(nums);
    for (auto ele : nums) cout << ele << '\t';
    cout << endl;
    return 0;
}
