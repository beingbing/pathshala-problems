#include <queue>
#include <vector>
using namespace std;

class Engineer {
    public:
    int spd, efcncy;
    Engineer(int &s, int &e): spd{s}, efcncy{e} {}
};

bool comp(Engineer& a, Engineer &b) {
    return a.efcncy > b.efcncy;
}

struct comprtr { 
    bool operator() (Engineer &a, Engineer &b) {
      return a.spd > b.spd;
    }
};

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> engnrs;
        for (int i{0}; i<n; i++) engnrs.push_back({speed[i], efficiency[i]});
        sort(engnrs.begin(), engnrs.end(), comp);
        priority_queue<Engineer, vector<Engineer>, comprtr> curTeam;
        long long teamSpd{0}, mxPrfrmnc{0};
        for (Engineer &newHire : engnrs) {
            if (curTeam.size() == k) {
                Engineer slowGuy = curTeam.top();
                teamSpd -= slowGuy.spd;
                curTeam.pop();
            }
            curTeam.push(newHire);
            teamSpd += newHire.spd;
            long long prformncWithNewGuy = teamSpd * (long) newHire.efcncy;
            mxPrfrmnc = max(mxPrfrmnc, prformncWithNewGuy);
        }
        return (int) (mxPrfrmnc % 1000000007);
    }
};
