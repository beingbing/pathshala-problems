#include <queue>
#include <vector>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
public:
    KthLargest(int k, vector<int>& nums): pq{nums.begin(), nums.end()}, kth{k} {}
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > kth) pq.pop();
        return pq.top();
    }
};
