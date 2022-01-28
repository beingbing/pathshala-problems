#include <queue>
#include <vector>
using namespace std;

struct Comp {
    bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
        long d1 = p1.first * p1.first + p1.second * p1.second;
        long d2 = p2.first * p2.first + p2.second * p2.second;
        return d1 > d2;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> pts;
        for (auto &ele : points) pts.push_back({ele[0], ele[1]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq(pts.begin(), pts.end());
        vector<vector<int>> ans;
        for (int i{0}; i<k; i++) {
            pair<int, int> pt = pq.top();
            ans.push_back({pt.first, pt.second});
            pq.pop();
        }
        return ans;
    }
};
