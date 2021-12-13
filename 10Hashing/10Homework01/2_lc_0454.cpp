#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int n = nums1.size();
        unordered_map<int, int> pairSum;
        for (int i{0}; i < n; i++)
            for (int j{0}; j < n; j++)
                pairSum[nums1[i] + nums2[j]]++;
        int cnt{0};
        for (int i{0}; i < n; i++)
            for (int j{0}; j < n; j++)
                if (pairSum.find(-1 * (nums3[i] + nums4[j])) != pairSum.end())
                    cnt += pairSum[-1 * (nums3[i] + nums4[j])];
        return cnt;
    }
};

int main() {
    vector<int> nums1 = {-1, 1, 1, 1, -1}, nums2 = {0, -1, -1, 0, 1}, nums3 = {-1, -1, 1, -1, -1}, nums4 = {0, 1, 0, -1, -1};
    Solution obj;
    cout << obj.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}
