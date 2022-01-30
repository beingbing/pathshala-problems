#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Job {
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution {

    static bool Comp(Job& a, Job& b) {
        if (a.profit == b.profit) return a.dead > b.dead;
        return a.profit > b.profit; 
    }

public:
    vector<int> JobScheduling(Job a[], int n) {
        map<int, bool> slots;
        for (int i{1}; i<=n; i++) slots[i] = false;
        sort(a, a+n, Comp);
        int mxPrft = 0;
        int cnt{0};
        for (int i{0}; i<n; i++) {
            int val = a[i].dead;
            auto itr = slots.upper_bound(val);
            if (itr != slots.begin()) {
                cnt++;
                itr--;
                slots.erase(itr);
                mxPrft += a[i].profit;
            }
        }
        vector<int> ans = {cnt, mxPrft};
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Job arr[n];
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        vector<int> mxPrft = ob.JobScheduling(arr, n);
        cout << mxPrft[0] << " " << mxPrft[1] << endl;
    }
    return 0;
}
