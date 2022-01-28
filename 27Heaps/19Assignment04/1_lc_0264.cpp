#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Comp {
    bool operator() (long long& a, long long& b) {
        return a > b;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, Comp> pq;
        unordered_map<long long, bool> ump;
        vector<int> primes = {2,3,5};
        pq.push(1);
        ump[1] = true;
        long long ans;
        while (n--) {
            ans = pq.top();
            pq.pop();
            for (auto &ele : primes) {
                if (ump.find(ans*ele) != ump.end()) continue;
                pq.push(ans*ele);
                ump[ans*ele] = true;
            }
        }
        return ans;
    }
};
