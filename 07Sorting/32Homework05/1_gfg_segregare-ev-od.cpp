#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void segregateEvenOdd(vector<int>& a, int n) {
        int i = 0, cnt = 0;
        while (i < n) {
            if (a[i] % 2 == 0) {
                swap(a[cnt], a[i]);
                cnt++;
            }
            i++;
        }
        sort(a.begin(), a.begin() + cnt);
        sort(a.begin() + cnt, a.end());
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
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
