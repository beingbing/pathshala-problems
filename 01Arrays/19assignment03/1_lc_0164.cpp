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
        int gap = (maxNum-minNum)/(n-1);
        if ((maxNum-minNum)%(n-1) != 0) gap++;
        vector<int> minArr(n, INT_MAX), maxArr(n, INT_MIN);
        int bkt;
        for (auto ele : nums) {
            bkt = (ele - minNum)/gap;
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