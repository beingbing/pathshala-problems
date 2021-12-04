#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int TotalPairs(vector<int> a, int diff) {
        int i = 0, j = 1, c = 0, n = a.size();
        sort(a.begin(), a.end());
        while (j < n) {
            int cur = a[j] - a[i];
            if (cur < diff) j++;
            else if (cur > diff) {
                i++;
                if (i == j) j++;
            } else {
                int p = a[i], q = a[j];
                if (diff == 0) {
                    while (a[i] == p) i++, j++;
                    c++;
                } else {
                    while (a[i] == p) i++;
                    while (a[j] == q) j++;
                    c++;
                }
            }
        }
        return c;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.TotalPairs(nums, k);
        cout << ans << "\n";
    }
    return 0;
}
