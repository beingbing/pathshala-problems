// leetcode problem link
// https://leetcode.com/problems/check-if-it-is-a-good-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    int calcGCD(int a, int b) {
        int x = min(a, b);
        int y = max(a, b);
        if (x == 0)
            return y;
        if (y % x == 0)
            return x;
        return calcGCD(y % x, x);
    }

public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for (int ele: nums)
            res = calcGCD(res, ele);
        return res == 1;
    }
};

int main() {
    Solution obj;
    vector<int> ar = {12,5,7,23};
    cout << obj.isGoodArray(ar) << endl;
    
    return 0;
}