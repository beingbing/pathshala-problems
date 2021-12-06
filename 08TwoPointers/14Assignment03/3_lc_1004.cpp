#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j;
        int n = nums.size();
        for (j = 0; j < n; j++) {
            if (nums[j] == 0) k--; // expand window until we have capacity to flip 0s
            if (k < 0) { // once the capacity is exhausted
                k += ((nums[i] == 0) ? 1 : 0); // keep the window size same and move window forward
                i++;
            }
        }
        return j - i; // here +1 is not done because it is already included in j
    }
};

int main() {
    vector<int> nums = {1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1};
    int k = 8;
    Solution obj;
    cout << obj.longestOnes(nums, 8) << endl;
    return 0;
}
