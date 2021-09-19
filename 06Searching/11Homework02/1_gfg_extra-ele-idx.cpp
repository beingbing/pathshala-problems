// { Driver Code Starts
#include <iostream>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (mid == 0) {
                if (a[mid] != b[mid]) return mid;
                else low = mid+1;
            } else if (mid == n-1) {
                if (a[mid] != b[mid-1]) return mid;
                else high = mid - 1;
            } else {
                if (a[mid] == b[mid]) low = mid+1;
                else {
                    if (a[mid-1] == b[mid-1]) return mid;
                    high = mid-1;
                }
            }
        }
        return n-1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}  // } Driver Code Ends