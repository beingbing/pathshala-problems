// find sum of all subarrays of given array

// { Driver Code Starts
//Initial template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    long long subarraySum(long long a[], long long n) {
        long long int mod = 1000000007;
        long long int ans{0};
        for (long long int i{0}; i < n; i++) {
            // ans += (i+1)*(n-i)*a[i]
            ans = (ans % mod + (((((i + 1) % mod) * ((n - i) % mod)) % mod) * (a[i] % mod)) % mod) % mod;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long a[n + 5];
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.subarraySum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends