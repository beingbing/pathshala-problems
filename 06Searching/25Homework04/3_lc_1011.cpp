#include <iostream>
#include <vector>
using namespace std;

class Solution {

    bool isPossible(vector<int>& weights, int target, int& days, int& n) {
        int daysCnt = 1, weightSum = 0;
        for (int i{0}; i<n; i++) {
            if (weightSum + weights[i] > target) {
                daysCnt++;
                weightSum = weights[i];
            } else weightSum += weights[i];
        }
        return daysCnt <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low{INT_MIN}, high = 0, mid{0};
        for (int i{0}; i<n; i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }
        while (low <= high) {
            mid = low + (high - low)/2;
            if (!isPossible(weights, mid, days, n)) low = mid+1;
            else {
                if (!isPossible(weights, mid-1, days, n)) break;
                else high = mid-1;
            }
        }
        return mid;
    }
};

int main() {
    vector<int> weights = {1,2,3,1,1};
    Solution obj;
    cout << obj.shipWithinDays(weights, 4);
    return 0;
}
