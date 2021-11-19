#include <iostream>
#include <vector>
using namespace std;

class Solution {
    long long int findGCDM2(long long int a, long long int b) {
        long long int x = min(a, b);
        long long int y = max(a, b);
        if (x == 0) return y;
        if (y % x == 0) return x;
        return findGCDM2(y % x, x);
    }

    long long int findLCMM2(long long int a, long long int b) {
        long long int gcd = findGCDM2(a, b);
        return (a * b) / gcd;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long int lcmab = findLCMM2(a, b);
        long long int lcmbc = findLCMM2(b, c);
        long long int lcmca = findLCMM2(c, a);
        long long int lcmabc = findLCMM2(lcmab, c);
        long long int low = 0, high = (long)n * min(min(a, b), c);
        while (low <= high) {
            long long int mid = low + (high - low) / 2;
            if ((mid/a + mid/b + mid/c - mid/lcmab - mid/lcmbc - mid/lcmca + mid/lcmabc) < n) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main() {
    int n = 3, a = 2, b = 3, c = 5;
    Solution* obj = new Solution();
    cout << obj->nthUglyNumber(n, a, b, c) << endl;
    return 0;
}
