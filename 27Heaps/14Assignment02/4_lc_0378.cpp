#include <queue>
#include <set>
#include <vector>
using namespace std;

vector<vector<int>> m;

struct Comp {
    bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
        return m[p1.first][p1.second] > m[p2.first][p2.second];
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        m = mat;
        int row = mat.size(), col = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        pq.push({0,0});
        set<pair<int, int>> mp;
        mp.insert({0,0});
        vector<int> ans;
        while (k--) {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(m[p.first][p.second]);
            if (p.second+1 < col && mp.find({p.first, p.second+1}) == mp.end()) {
                pq.push({p.first, p.second+1});
                mp.insert({p.first, p.second+1});
            }
            if (p.first+1 < row && mp.find({p.first+1, p.second}) == mp.end()) {
                pq.push({p.first+1, p.second});
                mp.insert({p.first+1, p.second});
            }
        }
        return ans.back();
    }
};
