#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {
public:
    ll threeSum(vector<ll> &a, ll d) {
        ll ans{0}, n = a.size(), j{0};
        for (ll i{0}; i < n; i++) {
            while (a[i] - a[j] > d) j++;
            ans += 1LL * (i - j) * (i - j - 1) * 0.5;
        }
        return ans;
    }
};

int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> nums(n);
    for (ll i{0}; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.threeSum(nums, d) << endl;
    return 0;
}
