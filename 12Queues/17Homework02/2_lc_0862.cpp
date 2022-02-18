/*

What is the purpose of second while loop?
To keep pfSum[dq[i]] increasing in the deque.


Why keep the deque increase?
If pfSum[i] <= pfSum[dq.back()] and moreover we already know that i > dq.back(), it means
that compared with dq.back(), pfSum[i] can help us make the subarray length shorter (as it will be
the starting index of our subarray in first while loop and) and sum bigger.
So no need to keep d.back() in our deque.

*/
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
            while (!dq.empty() && pfSum[i] - pfSum[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && pfSum[dq.back()] >= pfSum[i]) dq.pop_back();
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