#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenOfLongSubarr(int a[], int n, int k) {
        unordered_map<int, int> pfSumIdx;
        int pfSum{0}, ans{0};
        pfSumIdx[pfSum] = -1;
        for (int i{0}; i < n; i++) {
            pfSum += a[i];
            if (pfSumIdx.find(pfSum - k) != pfSumIdx.end()) ans = max(ans, i - pfSumIdx[pfSum - k]);
            if (pfSumIdx.find(pfSum) == pfSumIdx.end()) pfSumIdx[pfSum] = i;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }
    return 0;
}
