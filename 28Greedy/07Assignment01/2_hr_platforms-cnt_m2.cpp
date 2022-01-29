#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool Comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n; 
    cin >> n;
    vector<int> arrival(n), departure(n);
    for (int i{0}; i<n; i++) cin >> arrival[i] >> departure[i];
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int ans{0}, curCnt{0}, arvl{0}, dprtr{0};
    while (arvl < n && dprtr < n) {
        if (arrival[arvl] < departure[dprtr]) arvl++, curCnt++;
        else dprtr++, curCnt--;
        ans = max(ans, curCnt);
    }
    curCnt += n-arvl; // just in case departure array got ended and arrival array has elements left
    ans = max(ans, curCnt);
    cout << ans << endl;
    return 0;
}
