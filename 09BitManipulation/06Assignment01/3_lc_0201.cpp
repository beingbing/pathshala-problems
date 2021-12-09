#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long mask = 1L << 31, ans = 0;
        while (mask) {
            if ((mask & left) == (mask & right)) {
                if (mask & left) ans += mask;
                mask >>= 1;
            } else break;
        }
        return ans;
    }
};

int main() {
    int left = 1, right = 2147483647;
    Solution obj;
    cout << obj.rangeBitwiseAnd(left, right) << endl;
    return 0;
}
