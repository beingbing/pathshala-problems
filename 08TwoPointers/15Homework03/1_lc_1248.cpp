#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isOdd(int n) {
        return n % 2 != 0;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int i = 0, j, cnt{0}, total{0};
        int n = nums.size();
        for (j = 0; j < n; j++) {
            if (isOdd(nums[j])) {
                k--;
                cnt = 0;
            }
            while (k == 0) {
                cnt++;
                k += (isOdd(nums[i]) ? 1 : 0);
                i++;
            }
            total += cnt;
        }
        return total;
    }
};

int main() {
    vector<int> nums = {1, 2, 4, 6, 3, 5, 8, 2, 7, 9, 4};
    int k = 3;       // 0  1  2  3  4  5  6  7  8  9  10
    Solution obj;
    cout << obj.numberOfSubarrays(nums, k) << endl;
    return 0;
}
