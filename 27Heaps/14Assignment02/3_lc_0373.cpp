#include <queue>
#include <set>
#include <vector>
using namespace std;

vector<int> a1, a2;

struct Comp {
    bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
        return a1[p1.first] + a2[p1.second] > a1[p2.first] + a2[p2.second];
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        a1 = a, a2 = b;
         k = k > (a.size() * b.size()) ? a.size() * b.size() : k;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        pq.push({0,0});
        set<pair<int, int>> mp;
        mp.insert({0,0});
        vector<vector<int>> ans;
        while (k--) {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back({a[p.first], b[p.second]});
            if (p.second+1 < b.size() && mp.find({p.first, p.second+1}) == mp.end()) {
                pq.push({p.first, p.second+1});
                mp.insert({p.first, p.second+1});
            }
            if (p.first+1 < a.size() && mp.find({p.first+1, p.second}) == mp.end()) {
                pq.push({p.first+1, p.second});
                mp.insert({p.first+1, p.second});
            }
        }
        return ans;
    }
};
