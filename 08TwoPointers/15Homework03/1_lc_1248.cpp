#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isOdd(int n) {
        return n % 2 != 0;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int left = 0, right, prefixEven{0}, result{0};
        int n = nums.size();
        for (right = 0; right < n; right++) {
            if (isOdd(nums[right])) {
                k--;
                prefixEven = 0;
            }
            while (k == 0) {
                prefixEven++;
                k += (isOdd(nums[left]) ? 1 : 0);
                left++;
            }
            result += prefixEven;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 4, 6, 3, 5, 8, 2, 7, 9, 4};
    int k = 3;       // 0  1  2  3  4  5  6  7  8  9  10
    Solution obj;
    cout << obj.numberOfSubarrays(nums, k) << endl;
    return 0;
}
