#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

ll sumRegion(ll row1, ll col1, ll row2, ll col2, vector<vector<ll>>& sumMat) {
    if (row1 == 0 and col1 == 0) return sumMat[row2][col2];
    if (row1 == 0 and col1 > 0) return sumMat[row2][col2] - sumMat[row2][col1 - 1];
    if (row1 > 0 and col1 == 0) return sumMat[row2][col2] - sumMat[row1 - 1][col2];
    return sumMat[row2][col2] - sumMat[row2][col1 - 1] - sumMat[row1 - 1][col2] + sumMat[row1 - 1][col1 - 1];
}

bool foundSquare(ll mid, vector<vector<ll>> pxlMat, ll k) {
    ll n = pxlMat.size();
    ll m = pxlMat[0].size();
    vector<vector<ll>> mat(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) if (0 <= pxlMat[i][j] && pxlMat[i][j] <= mid) mat[i][j] = 1;
    // another way of creating sum matrix
    for (ll i = 0; i < n; i++) for (ll j = 1; j < m; j++) mat[i][j] += mat[i][j - 1];
    for (ll i = 0; i < m; i++) for (ll j = 1; j < n; j++) mat[j][i] += mat[j - 1][i];
    
    for (ll i = 0; i < n-k+1; i++) {
        for (ll j = 0; j < m-k+1; j++) {
            ll ans = sumRegion(i, j, i+k-1, j+k-1, mat);
            if (ans >= k * k) return true;
        }
    }
    return false;
}

int main() {
    ll len, wid, sz, pxlCnt;
    cin >> len >> wid >> sz >> pxlCnt;
    ll x, y, mn{INT_MAX}, mx{INT_MIN};
    vector<vector<ll>> mat(len, vector<ll>(wid, -1));
    for (ll i{0}; i < pxlCnt; i++) {
        cin >> x >> y;
        cin >> mat[x - 1][y - 1];
        mn = min(mn, mat[x - 1][y - 1]);
        mx = max(mx, mat[x - 1][y - 1]);
    }
    ll low = mn, high = mx, mid, ans{-1};
    if (pxlCnt == 0) {
        cout << ans << endl;
        return 0;
    }
    if (sz == 1) {
        cout << low << endl;
        return 0;
    }
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (!foundSquare(mid, mat, sz)) low = mid + 1;
        else {
            if (!foundSquare(mid - 1, mat, sz)) {
                ans = mid;
                break;
            } else high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}