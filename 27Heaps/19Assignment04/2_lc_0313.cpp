#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

vector<ll> nums;

struct Comp {
    bool operator() (pair<ll, ll>& p1, pair<ll, ll>& p2) {
        return p1.first * nums[p1.second] > p2.first * nums[p2.second];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        nums.clear();
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Comp> pq;
        nums.push_back(1); // at index 0 we have 1, so 0: 1
        for (auto &ele : primes) pq.push({ele, 0}); // all k elements present in primes are pointing to 0th index element
        while (nums.size() < n) {
            pair<ll, ll> p = pq.top();
            pq.pop();
            if (p.first * nums[p.second] > nums.back()) nums.push_back(p.first * nums[p.second]);
            pq.push({p.first, p.second+1}); // increase the indexing on which we are pointing
        }
        return nums.back();
    }
};
