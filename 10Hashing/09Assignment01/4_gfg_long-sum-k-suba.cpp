#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenOfLongSubarr(int a[], int n, int k) {
        unordered_map<int, int> pfSumIdx;
        int curSum{0}, len{0};
        pfSumIdx[0] = -1;
        for (int i{0}; i < n; i++) {
            curSum += a[i];
            if (pfSumIdx.find(curSum - k) != pfSumIdx.end()) len = max(len, i - pfSumIdx[curSum - k]);
            if (pfSumIdx.find(curSum) == pfSumIdx.end()) pfSumIdx[curSum] = i;
        }
        return len;
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
