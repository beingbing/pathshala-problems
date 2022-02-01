#include <iostream>
using namespace std;

class Solution {
public:
    long long numberOfWays(long long n) {
        if (n == 0) return 0;
        long long int f{1}, s{2}, tmp;
        if (n == 1) return f;
        for (int i{3}; i<=n; i++) {
            tmp = f + s;
            f = s;
            s= tmp;
        }
        return s;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
