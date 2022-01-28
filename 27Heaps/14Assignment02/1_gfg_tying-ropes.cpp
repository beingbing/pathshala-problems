#include <iostream>
#include <queue>
using namespace std;

struct Comp {
    bool operator() (long long& a, long long& b) {
        return a > b;
    }
};

class Solution {
public:
    long long minCost(long long ar[], long long n) {
        priority_queue<long long, vector<long long>, Comp> pq(ar, ar + n);
        long long ans = 0;
        while (pq.size() != 1) {
            long long min1 = pq.top();
            pq.pop();
            long long min2 = pq.top();
            pq.pop();
            ans += min1+min2;
            pq.push(min1+min2);
        }
        return ans;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
