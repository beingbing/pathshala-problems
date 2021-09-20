class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        while (low <= high) {
            long long int mid = low + (high-low)/2;
            if (mid * mid > x) high = mid-1;
            else {
                if ((mid+1)*(mid+1) > x) return mid;
                else low = mid+1;
            }
        }
        return 1;
    }
};