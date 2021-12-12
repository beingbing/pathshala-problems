#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        unordered_map<int, int> remdrCnt;
        int sum{0};
        for (auto ele : nums) {
            sum += ((ele % k) + k) % k;
            remdrCnt[sum % k]++;
        }
        int ans = remdrCnt[0];
        for (int i{0}; i < k; i++)
            if (remdrCnt.find(i) != remdrCnt.end())
                ans += (remdrCnt[i] * (remdrCnt[i] - 1)) / 2;
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    Solution obj;
    cout << obj.subarraysDivByK(nums, k) << endl;
    return 0;
}
