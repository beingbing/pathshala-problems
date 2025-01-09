#include <iostream>
using namespace std;

bool isBadVersion(int version);

int b;

bool isBadVersion(int n) {
    if (n < b) return false;
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool x = isBadVersion(mid-1);
            bool y = isBadVersion(mid);
            if (!x && y) return mid;
            if (!x && !y) low = mid+1;
            if (x && y) high = mid-1;
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n >> b;
    Solution* obj = new Solution();
    cout << obj->firstBadVersion(n) << endl;
}

public class Solution {
    private boolean isBadVersion(int version) {
        // Implementation hidden; returns true if version is bad, false otherwise.
    }

    public int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        // Perform binary search
        while (left < right) {
            int mid = left + (right - left) / 2; // Prevent overflow

            if (isBadVersion(mid)) right = mid; // If mid is bad, the first bad version is at mid or before
            else left = mid + 1; // If mid is good, search in the right half
        }

        // Left now points to the first bad version
        return left;
    }
}
