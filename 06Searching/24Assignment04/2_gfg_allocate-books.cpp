#include <iostream>
using namespace std;

class Solution {

    bool isPossible(int a[], int pgCnt, int&n, int& m) {
        int studentsCnt = 1, pagesSum = 0;
        for (int i{0}; i<n; i++) {
            if (pagesSum + a[i] > pgCnt) {
                studentsCnt++;
                pagesSum = a[i];
            } else pagesSum += a[i];
        }
        return studentsCnt <= m;
    }

public:
    int findPages(int a[], int n, int m) {
        if (m > n) return -1;
        int low{INT_MIN}, high = 0;
        for (int i{0}; i<n; i++) {
            low = max(low, a[i]);
            high += a[i];
        }
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (!isPossible(a, mid, n, m)) low = mid+1;
            else {
                if (!isPossible(a, mid-1, n, m)) return mid;
                else high = mid-1;
            }
        }
        return low;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) cin >> A[i];
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
