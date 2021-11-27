#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

void voteEveryone(ll i, ll j, vector<ll> &votes) {
    votes[j]++;
    if (i > 0) votes[i - 1]--;
}

ll sum(ll i, ll j, vector<ll> &pfsum) {
    if (i == 0) return pfsum[j];
    else if (i-1 <= j) return pfsum[j] - pfsum[i - 1];
    return LLONG_MAX;
}

bool isPossibleL(ll& i, ll m, ll &val, vector<ll> &pfsum) {
    if (sum(m + 1, i - 1, pfsum) <= val) return true;
    return false;
}

ll findLeft(ll i, vector<ll> &influence, vector<ll> &pfsum) {
    ll low = 0, high = i - 1;
    while (low <= high) {
        ll m = (low + high) / 2;
        if (isPossibleL(i, m, influence[i], pfsum)) high = m - 1;
        else {
            if (isPossibleL(i, m + 1, influence[i], pfsum)) return m;
            else low = m + 1;
        }
    }
    return high;
}

bool isPossibleR(ll& i, ll mid, ll &val, vector<ll> &pfsum) {
    if (sum(i + 1, mid - 1, pfsum) <= val) return true;
    return false;
}

ll findRight(ll i, vector<ll> &influence, vector<ll> &pfSum) {
    ll low = i + 1, high = influence.size() - 1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (isPossibleR(i, mid, influence[i], pfSum)) low = mid + 1;
        else {
            if (isPossibleR(i, mid - 1, influence[i], pfSum)) return mid;
            else high = mid - 1;
        }
    }
    return low;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int cands;
        cin >> cands;
        vector<ll> influence(cands, 0);
        for (int i{0}; i < cands; i++) cin >> influence[i];
        vector<ll> pfSum(cands, 0);
        pfSum[0] = influence[0];
        for (int i{1}; i < cands; i++) pfSum[i] = pfSum[i - 1] + influence[i];
        vector<ll> votes(cands, 0);
        for (int i{0}; i < cands - 1; i++) {
            ll j = findRight(i, influence, pfSum);
            voteEveryone(i + 1, j - 1, votes);
        }
        for(int i{1}; i < cands; i++) {
            ll k = findLeft(i, influence, pfSum);
            voteEveryone(k + 1, i - 1, votes);
        }
        for (int i = cands - 2; i >= 0; i--) votes[i] = votes[i] + votes[i + 1];
        for (auto ele : votes) cout << ele << " ";
        cout << endl;
    }
    return 0;
}
