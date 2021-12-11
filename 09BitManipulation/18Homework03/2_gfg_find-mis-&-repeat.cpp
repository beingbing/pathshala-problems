#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *a, int n) {
        int *ans = new int[2], x{0};
        for (int i{1}; i<=n; i++) x ^= i;
        for (int i{0}; i<n; i++) x ^= a[i];
        int leastSetBit = 1;
        while (!(leastSetBit & x)) leastSetBit <<= 1;
        sort(a, a+n);
        vector<int> aBucket, bBucket;
        for (int i{0}; i<n; i++) {
            if (a[i] & leastSetBit) aBucket.push_back(a[i]);
            else bBucket.push_back(a[i]);
        }
        if (aBucket.size() > 0) {
            for (int i{0}; i<aBucket.size()-1; i++)  {
                if (aBucket[i] == aBucket[i+1]) {
                    ans[0] = aBucket[i];
                    break;
                }
            }
        }
        if (bBucket.size() > 0) {
            for (int i{0}; i<bBucket.size()-1; i++)  {
                if (bBucket[i] == bBucket[i+1]) {
                    ans[0] = bBucket[i];
                    break;
                }
            }
        }
        ans[1] = x^ans[0];
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
