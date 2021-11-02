// max gap problem: bucketing

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int maxNum = INT_MIN, minNum = INT_MAX;
        for (auto ele : nums) {
            maxNum = max(maxNum, ele);
            minNum = min(minNum, ele);
        }
        if (maxNum == minNum) return 0;
        // if there are n elements then there will be n-1 gaps between them
        int gap = (maxNum-minNum)/(n-1);
        // gap: minimum possible value of our answer, answer >= gap
        if ((maxNum-minNum)%(n-1) != 0) gap++;
        // if it is not perfectly divisible, then one gap will be greater than others
        // hence +1
        vector<int> minArr(n, INT_MAX), maxArr(n, INT_MIN);
        // minArr: contain minimum values of n buckets
        // maxArr: contain maximum values of n buckets
        int bkt;
        for (auto ele : nums) {
            // find bucket in which that element will go
            bkt = (ele - minNum)/gap;
            // check if that element contributes in either minimum or maximum
            // element of that array
            minArr[bkt] = min(minArr[bkt], ele);
            maxArr[bkt] = max(maxArr[bkt], ele);
        }
        int ans = INT_MIN, prev = INT_MIN;
        for (int i{0}; i<n; i++) {
            if (minArr[i] == INT_MAX) continue;
            if (prev == INT_MIN) prev = maxArr[i];
            else {
                ans = max(ans, minArr[i]-prev);
                prev = maxArr[i];
            }
        }
        return ans;
    }
};