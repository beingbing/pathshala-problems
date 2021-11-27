#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:	
	vector<int> printUnsorted(vector<int>& a, int n) {
        vector<int> preMax(n, 0), sufMin(n, 0);
        preMax[0] = a[0];
        for (int i{1}; i<n; i++) preMax[i] = max(preMax[i-1], a[i]);
        int y{0};
        for (int i{n-1}; i>=0; i--) if (a[i] != preMax[i]) {
            y = i;
            break;
        }
        sufMin[n-1] = a[n-1];
        for (int i{n-2}; i>=0; i--) sufMin[i] = min(sufMin[i+1], a[i]);
        int x{0};
        for (int i{0}; i<n; i++) if (a[i] != sufMin[i]) {
            x = i;
            break;
        }
        return {x, y};
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
