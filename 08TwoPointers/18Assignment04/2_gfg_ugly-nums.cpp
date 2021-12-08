#include <iostream>
#include <vector>
using namespace std;
#define ull unsigned long long

class Solution{
public:	
	ull getNthUglyNo(int n) {
        vector<ull> a(n);
        a[0] = 1;
        ull p1 = 0, p2 = 0, p3 = 0;
        for (ull i{1}; i<n; i++) {
            ull val = min(a[p1]*2, min(a[p2]*3, a[p3]*5));
            a[i] = val;
            if (val == a[p1]*2) p1++;
            if (val == a[p2]*3) p2++;
            if (val == a[p3]*5) p3++;
        }
        return a[n-1];
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
