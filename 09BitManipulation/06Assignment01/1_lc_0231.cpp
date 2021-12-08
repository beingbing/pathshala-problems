#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        ll num = (ll) n;
        return !(num&(num-1));
    }
};

int main() {
    ll n = 1024;
    Solution obj;
    cout << obj.isPowerOfTwo(n) << endl;
    return 0;
}
