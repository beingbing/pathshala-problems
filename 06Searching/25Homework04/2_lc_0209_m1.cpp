#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    bool isPossible(vector<int>& a, int len, int& target, int& n) {
        int sum{0};
        for (int i{0}; i<len; i++) sum += a[i];
        for (int i{len}; i<n; i++) {
            if (sum >= target) return true;
            sum += a[i];
            sum -= a[i-len];
        }
        if (sum >= target) return true;
        return false;
    }

public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n = a.size();
        int low{0}, high = n, mid{0};
        while (low <= high) {
            mid = low + (high - low)/2;
            if (!isPossible(a, mid, target, n)) low = mid + 1;
            else {
                if (!isPossible(a, mid-1, target, n)) return mid;
                else high = mid-1;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    Solution obj;
    cout << obj.minSubArrayLen(7, nums) << endl;
    return 0;
}