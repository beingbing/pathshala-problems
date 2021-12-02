#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {
    ll cnt{0}, lower, upper;

    void merge(vector<ll> &a, ll &s1, ll &e1, ll &e2) {
        ll s2{e1 + 1};
        ll fstVal = s2, lstVal = s2;  
        for (ll k{s1}; k <= e1; k++) {
            while (fstVal <= e2 && a[fstVal] - a[k] < lower) fstVal++;
            while (lstVal <= e2 && a[lstVal] - a[k] <= upper) lstVal++;
            cnt += (lstVal - fstVal);
        }
        ll i = s1, j = s2, c = s1;
        ll tmp[e2+1];
        while (i <= e1 && j <= e2) {
            if (a[i] <= a[j]) tmp[c++] = a[i++];
            else tmp[c++] = a[j++];
        }
        while (i <= e1) tmp[c++] = a[i++];
        while (j <= e2) tmp[c++] = a[j++];
        for (i = s1; i <= e2; i++) a[i] = tmp[i];
    }

    void mergeSort(vector<ll> &a, ll l, ll r) {
        if (l == r) return;
        ll m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }

public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        ll n = nums.size();
        this->lower = lower;
        this->upper = upper;
        vector<ll> pfSum(n);
        pfSum[0] = nums[0];
        if (pfSum[0] >= lower && pfSum[0] <= upper) cnt++;
        for (ll i = 1; i < n; i++) {
            pfSum[i] = pfSum[i - 1] + nums[i];
            if (pfSum[i] >= lower && pfSum[i] <= upper) cnt++;
        }
        mergeSort(pfSum, 0, n-1);
        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i{0}; i < n; i++)
            cin >> nums[i];
        int lower, upper;
        cin >> lower >> upper;
        Solution obj;
        cout << obj.countRangeSum(nums, lower, upper) << endl;
    }
    return 0;
}
