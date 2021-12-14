// https://asdfcoding.wordpress.com/2015/07/03/557c-arthur-and-table-codeforces/
// - group the legs by length
// - for each group, assume that it will be our max_len
// - we will try to remove legs outside of this group (size - k) in a way that minimize energy spent
//      - remove all groups with len > curGrpLen and record their energy
//      - for groups with len < curGrpLen allow only k-1 legs 
// - return the min energy spent after considering all the groups
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

multiset<int, greater<int>> shortLegsEnergy;
int cumEnergyOfShorterLegs = 0;

void calEnergySfSum(vector<int> &energySfSum, vector<pair<int, int>>& legs, int& legsCnt) {
    energySfSum[legsCnt] = 0;
    energySfSum[legsCnt - 1] = legs[legsCnt - 1].second;
    for (int i{legsCnt - 2}; i >= 0; i--) energySfSum[i] = energySfSum[i + 1] + legs[i].second;
}

int energySpent(vector<int> &energySfSum, vector<pair<int, int>> &legs, int sameSzLegsCnt, int curGrpStrt, int curGrpEnd) {
    // energy of longer legs removed + energy of shorter legs removed
    int total_energy = energySfSum[curGrpEnd + 1] + cumEnergyOfShorterLegs;
    auto it = shortLegsEnergy.begin();
    int allowedShorterLegsCnt = sameSzLegsCnt-1;
    for (int i = 0; i < allowedShorterLegsCnt && it != shortLegsEnergy.end(); i++) {
        // subtract energy of shorter legs which are allowed to stay
        total_energy -= (*it);
        it++;
    }
    for (int i = curGrpStrt; i <= curGrpEnd; i++) {
        shortLegsEnergy.insert(legs[i].second);
        cumEnergyOfShorterLegs += legs[i].second;
    }
    return total_energy;
}

int main() {
    int legsCnt;
    cin >> legsCnt;
    vector<pair<int, int>> legs(legsCnt);
    for (int i{0}; i < legsCnt; i++) cin >> legs[i].first;
    for (int i{0}; i < legsCnt; i++) cin >> legs[i].second;
    sort(legs.begin(), legs.end());
    vector<int> energySfSum(legsCnt+1);
    calEnergySfSum(energySfSum, legs, legsCnt);
    int ans = INT_MAX;
    int sameSzLegsCnt = 1; // count of legs of same length
    int curLen = legs[0].first;
    int curGrpStrt = 0;
    for (int i = 1; i < legsCnt; i++) {
        if (legs[i].first != curLen) {
            // Process the set of legs
            int energy = energySpent(energySfSum, legs, sameSzLegsCnt, curGrpStrt, i - 1);
            ans = min(ans, energy);
            sameSzLegsCnt = 1;
            curGrpStrt = i;
            curLen = legs[i].first;
        } else sameSzLegsCnt++;
    }

    int energy = energySpent(energySfSum, legs, sameSzLegsCnt, curGrpStrt, legsCnt - 1);
    cout << min(ans, energy) << endl;
    return 0;
}
