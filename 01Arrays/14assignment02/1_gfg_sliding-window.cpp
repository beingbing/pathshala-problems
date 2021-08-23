// minimum swaps required to bring all element less than or equal to k together

// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k);

// Driver code
int main() {

    int t, n, k;
    cin >> t;
    cout << "t is: " << t << endl;
    cout << endl;
    while (t--) {
        cin >> n;
        cout << "n is: " << n << endl;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            // cout << i << " " << arr[i] << endl;
        }
        cin >> k;
        cout << "k is: " << k << endl;
        cout << minSwap(arr, n, k) << "\n";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

int minSwap(int *a, int n, int k) {
    int legalEles{0};
    for (int i{0}; i < n; i++) if (a[i] <= k) legalEles++;
    int maxCnt{0}, freq{0};
    // legalEles is my sliding window size
    for (int i{0}; i < legalEles; i++) if (a[i] <= k) freq++;
    for (int i{legalEles}; i < n; i++) {
        if (freq > maxCnt) maxCnt = freq;
        if (a[i] <= k) freq++;
        if (a[i - legalEles] <= k) freq--;
    }
    if (freq > maxCnt) maxCnt = freq;
    return legalEles - maxCnt;
}
