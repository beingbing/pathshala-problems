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

```java
public class Solution {
    public static int findExtraElementIndex(int[] A, int[] B) {
        int low = 0;
        int high = A.length - 2; // B has one less element than A

        while (low <= high) {
            int mid = (low + high) / 2;

            // If they are the same, extra element must be in the right half
            if (A[mid] == B[mid]) low = mid + 1;
            else high = mid - 1; // If they are different, the extra element is at mid or in the left half
        }

        // 'low' will be at the index of the extra element
        return low;
    }

    public static void main(String[] args) {
        // Example usage:
        int[] A = {2, 4, 6, 8, 9, 10, 12};
        int[] B = {2, 4, 6, 8, 10, 12};

        System.out.println(findExtraElementIndex(A, B)); // Output: 4
    }
}

```