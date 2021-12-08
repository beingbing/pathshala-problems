#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {
    public:
    ll solution(ll &n, vector<ll> &lightsaberClr, ll &m, vector<ll> &knightsCnt) {
        ll distClrs{0}, xtra{0};
        for (auto ele : knightsCnt) {
            if (ele > 0) distClrs++;
            xtra += ele;
        }
        unordered_map<ll, ll> tempFreq;
        ll c = 0, start = 0, end;
        for (ll i{0}; i<n; i++) {
            tempFreq[lightsaberClr[i]]++;
            if (tempFreq[lightsaberClr[i]] == knightsCnt[lightsaberClr[i]-1]) c++;
            if (c == distClrs) {end = i; break;}
        }
        if (c < distClrs) return -1;
        ll anss = start, anse = end, minm = end-start+1;
        while (end < n) {
            while (tempFreq[lightsaberClr[start]] > knightsCnt[lightsaberClr[start]-1])
                tempFreq[lightsaberClr[start]]--, start++;
            if (end-start+1 < minm) {
                minm = end-start+1;
                anss = start;
                anse = end;
            }
            end++;
            if (end < n) tempFreq[lightsaberClr[end]]++;
        }
        return minm - xtra;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> lightsaberClr(n);
    for (ll i{0}; i<n; i++) cin >> lightsaberClr[i];
    vector<ll> knightsCnt(m);
    for (ll i{0}; i<m; i++) cin >> knightsCnt[i];
    Solution obj;
    cout << obj.solution(n, lightsaberClr, m, knightsCnt) << endl;
    return 0;
}
