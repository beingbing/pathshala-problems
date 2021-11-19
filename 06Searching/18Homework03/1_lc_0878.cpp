#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int findGCDM2(int a, int b) {
        int x = min(a, b);
        int y = max(a, b);
        if (x == 0) return y;
        if (y%x == 0) return x;
        return findGCDM2(y%x, x);
    }

    int findLCMM2(int a, int b) {
        int gcd = findGCDM2(a, b);
        return (a*b)/gcd;
    }

public:
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7, lcm = findLCMM2(a, b);
        long long int low = 0, high = (long) n*min(a,b);
        while (low <= high) {
            long long int mid = low + (high-low)/2;
            if ((mid/a + mid/b - mid/lcm) < n) low = mid + 1;
             else high = mid - 1;
        }
        return low%MOD;
    }
};

int main() {
    int n = 25, a = 7, b = 3;
    Solution* obj = new Solution();
    cout << obj->nthMagicalNumber(n, a, b) << endl;
    return 0;
}
