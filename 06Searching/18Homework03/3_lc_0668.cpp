#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool enough(int x, int row, int col, int k) {
        int cnt = 0;
        for (int i = 1; i <= row; i++) cnt += min(x / i, col);
        return cnt >= k;
    }

public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!enough(mid, m, n, k)) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

int main() {
    int n = 9895, m = 28405, k = 100787757;
    Solution* obj = new Solution();
    cout << obj->findKthNumber(n, m, k) << endl;
    return 0;
}
