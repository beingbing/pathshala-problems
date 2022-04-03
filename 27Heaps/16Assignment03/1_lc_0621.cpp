#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> freq(26, 0);
        for (auto &ele : tasks) freq[ele-'A']++;
        for (auto &ele : freq) if (ele) pq.push(ele);
        int ans = 0;
        while (pq.size()) {
            int cnt = 0;    // n+1 steps will be covered in [0, n]
            vector<int> tmp;
            while (cnt <= n) { // one cycle completed
                if (pq.size() == 0) { // priority queue got emptied in middle of a cycle
                    if (tmp.size() > 0) ans += n-cnt+1; // but temp array still has elements: ideal intervals
                    break;
                }
                int x = pq.top();
                pq.pop();
                if (x-1 > 0) tmp.push_back(x-1);
                ans++;  // an interval of actual answer got executed
                cnt++;  // an interval of current cycle got executed
            }
            for (auto &ele : tmp) pq.push(ele);
        }
        return ans;
    }
};
