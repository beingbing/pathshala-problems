#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int curSum = 0, cnt{0};
        for (int i{0}; i<nums.size(); i++) {
            curSum += nums[i];
            if (curSum == k) cnt++;
            if (mp.find(curSum-k) != mp.end()) cnt += mp[curSum-k];
            mp[curSum]++;
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
