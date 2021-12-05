#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minDiff{INT_MAX}, ans;
        sort(nums.begin(), nums.end());
        for (int i{0}; i < n; i++) {
            int p1 = i+1, p2 = n-1;
            while (p1 < p2) {
                int sum = nums[i]+nums[p1]+nums[p2];
                if (sum == target) return target;
                else {
                    if (abs(target - sum) < minDiff) {
                        minDiff = abs(target-sum);
                        ans = sum;
                    }
                    sum < target ? p1++ : p2--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution obj;
    cout << obj.threeSumClosest(nums, target) << endl;
    return 0;
}