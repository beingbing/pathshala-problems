#include <iostream>
using namespace std;

class Solution{   
public:
    int getPairsCount(int a[], int n, int k) {
        int i = 0, j = n-1, ans{0};
        sort(a, a+n);
        while(i<j) {
            int sum = a[i] + a[j];
            if (k > sum) i++;
            else if (k < sum) j--;
            else {
                if (a[i] == a[j]) {
                    int l = j - i + 1;
                    ans += l*(l-1)/2;
                    break;
                }
                int v1 = a[i], v2 = a[j];
                int c1{0}, c2{0};
                while (a[i] == v1) i++, c1++;
                while (a[j] == v2) j--, c2++;
                ans += c1*c2;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
