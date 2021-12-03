#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& a, int n) {
        int i = 0, cnt = 0;
        while (i < n) {
            if (a[i] == 0) {
                swap(a[cnt], a[i]);
                cnt++;
            }
            i++;
        }
        for (i = 0; i < n; i++) if (a[i] != 0) break;
        cnt = i;
        while (i < n) {
            if (a[i] == 1) {
                swap(a[cnt], a[i]);
                cnt++;
            }
            i++;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        ob.sort012(a, n);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
