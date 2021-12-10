#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        long long int cnt{0}, mask = 1L << 31;
        for (int i{31}; i>=0; i--) {
            mask >>= 1;
            if ((c & mask)) {
                if (!(a & mask) && !(b & mask)) cnt++;
            } else {
                if ((a & mask) && (b & mask)) cnt += 2;
                else if (!(a & mask) && !(b & mask)) continue;
                else cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    int a = 2, b = 6, c = 5;
    Solution obj;
    cout << obj.minFlips(a, b, c) << endl;
    return 0;
}
