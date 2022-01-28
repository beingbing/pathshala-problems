#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<long long> nums;

struct Comp {
    bool operator() (pair<long long, long long>& p1, pair<long long, long long>& p2) {
        return p1.first * nums[p1.second] > p2.first * nums[p2.second];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        nums.clear();
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, Comp> pq;
        nums.push_back(1);
        for (auto &ele : primes) pq.push({ele, 0});
        while (nums.size() < n) {
            pair<long long, long long> p = pq.top();
            pq.pop();
            if (p.first * nums[p.second] > nums.back()) nums.push_back(p.first * nums[p.second]);
            pq.push({p.first, p.second+1});
        }
        return nums.back();
    }
};
