#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    ll friends, moneyDiff;
    cin >> friends >> moneyDiff;
    vector<pair<int, int>> a(friends);
    for (int i = 0; i < friends; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    ll slow{0}, preSum{0}, ans{0};
    for (int fast = 0; fast < friends; fast++) {
        if (a[fast].first - a[slow].first < moneyDiff) {
            preSum += a[fast].second;
            ans = max(ans, preSum);
        } else {
            preSum -= a[slow++].second;
            fast--;
        }
    }
    cout << ans;
    return 0;
}
