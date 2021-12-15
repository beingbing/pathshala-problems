#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pfSum = 0, cnt{0};
        mp[cnt] = 1;
        for (int i{0}; i<nums.size(); i++) {
            pfSum += nums[i];
            if (mp.find(pfSum-k) != mp.end()) cnt += mp[pfSum-k];
            mp[pfSum]++;
        }
        return cnt;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution obj;
    cout << obj.subarraySum(nums, 3) << endl;
    return 0;
}
