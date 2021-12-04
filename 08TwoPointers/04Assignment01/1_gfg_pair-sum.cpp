#include <iostream>
using namespace std;

class Solution {
public:
    bool hasArrayTwoCandidates(int a[], int n, int k) {
        int i = 0, j = n - 1;
        sort(a, a + n);
        while (i < j) {
            int sum = a[i] + a[j];
            if (k == sum) return true;
            else if (k > sum) i++;
            else j--;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
