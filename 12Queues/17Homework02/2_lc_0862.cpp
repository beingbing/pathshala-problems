#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int> &a, int k) {
        int n = a.size();
        vector<int> pfSum(n + 1, 0);
        for (int i = 0; i < n; ++i) pfSum[i + 1] = pfSum[i] + a[i];
        deque<int> dq;
        int ans = n + 1;
        for (int i = 0; i < n + 1; ++i) {
            // cout << "    i: " << i << endl;
            // for (auto ele : dq) cout << ele << " ";
            // cout << endl;
            while (!dq.empty() && pfSum[i] - pfSum[dq.front()] >= k) {
                // cout << "frnt " << dq.front() << endl;
                ans = min(ans, i - dq.front());
                // cout << "ans: " << ans << endl;
                dq.pop_front();
            }
            while (!dq.empty() && pfSum[dq.back()] >= pfSum[i]) {
                // cout << "bck " << dq.back() << endl;
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans <= n ? ans : -1;
    }
};

int main() {
    vector<int> nums = {9,3,3,-5,-2,12,-6,-12,4,15};
    int k = 18;
    Solution obj;
    cout << obj.shortestSubarray(nums, k) << endl;
    return 0;
}

/*
1. keep deque monotonically increasing, front will have smallest and back largest among candidates.
2. if front is small enough to give us answer, record it then drop front, as it is of no use now,
keep doing it until we get to a front which stops giving us answer.
3. if back is bigger than current than drop it, our current candidate can get us better answer with
future candidates.
*/