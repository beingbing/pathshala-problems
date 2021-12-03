#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& a) {
        int i = 0, cnt = 0, n = a.size();
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
        ob.sortColors(a);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
