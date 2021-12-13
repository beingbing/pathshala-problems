#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areConsecutives(long long a[], int n) {
        unordered_map<long long, long long> nums;
        long long mn = LLONG_MAX;
        for (long long i{0}; i < n; i++) {
            nums[a[i]] = 0;
            mn = min(mn, a[i]);
        }
        for (long long i{mn}; i <= (mn + n - 1); i++)
            if (nums.find(i) == nums.end())
                return false;
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        if (ob.areConsecutives(a, n) == true) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    return 0;
}
