#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();
        if (n == 1) {
            if (a[0] >= 1) return 1;
            else return 0;
        }
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (mid == 0) {
                if (a[mid] >= n) return n-mid;
                else low = mid+1;
            } else if (mid == n-1) {
                if (a[mid] >= 1) return n-mid;
                else high = mid-1;
            } else {
                if (a[mid] < n-mid) low = mid+1;
                else {
                    if (a[mid-1] < n-mid+1) return n-mid;
                    else high = mid - 1;
                }
            }
        }
        return 0;
    }
};