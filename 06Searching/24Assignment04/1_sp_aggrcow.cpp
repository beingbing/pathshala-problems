#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    bool isPossible(vector<int>& stalls, int dist, int& cows) {
        int n = stalls.size(), lastSelectedStall = stalls[0], cnt = 1;
        for (int i{1}; i<n; i++) {
            if (stalls[i] - lastSelectedStall < dist) continue;
            else {
                cnt++;
                lastSelectedStall = stalls[i];
            }
        }
        return cnt >= cows;
    }

public:
    int largestMinDist(vector<int>& stalls, int& n, int& c) {
        sort(stalls.begin(), stalls.end());
        int low{INT_MAX}, high = stalls[n - 1] - stalls[0];
        for (int i{1}; i < n; i++) low = min(low, stalls[i] - stalls[i - 1]);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (!isPossible(stalls, mid, c)) high = mid - 1;
            else {
                if (!isPossible(stalls, mid + 1, c)) return mid;
                else low = mid + 1;
            }
        }
        return low;
    }

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n, 0);
        for (int i{0}; i < n; i++) cin >> stalls[i];
        Solution* obj = new Solution();
        cout << obj->largestMinDist(stalls, n, c) << endl;
    }
    return 0;
}