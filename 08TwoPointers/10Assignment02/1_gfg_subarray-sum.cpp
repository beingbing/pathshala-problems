#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> subarraySum(int a[], int n, long long k) {
        int i = 0, j = 0;
        long long curSum = (long long)a[0];
        while (j < n) {
            if (curSum < (long long)k) {
                j++;
                if (j < n) curSum += (long long)a[j];
            } else if (curSum > (long long)k) {
                curSum -= (long long)a[i];
                i++;
                if (i > j) {
                    j++;
                    if (j < n) curSum = (long long)a[j];
                }
            } else return {i + 1, j + 1}; // {i, j}
        }
        return {-1}; // -1
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
