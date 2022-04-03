#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

struct Comp {
    bool operator() (ll& a, ll& b) {
        return a > b;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, Comp> pq;
        unordered_map<ll, bool> ump;
        vector<int> primes = {2,3,5};
        pq.push(1);
        ump[1] = true;
        ll ans;
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
