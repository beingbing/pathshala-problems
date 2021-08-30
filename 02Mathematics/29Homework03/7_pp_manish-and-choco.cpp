// codeforces problem link
// https://codeforces.com/problemset/problem/617/B

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ar(n), vals;
    int cnt{1};
    for (int i{0}; i<n; i++) cin >> ar[i];
    if (ar.size() == 1) {
        cout << ar[0] << endl;
        return 0;
    }
    int strt = 0;
    while (strt < n && ar[strt] != 1) strt++;
    int ed = n-1;
    while (ed >= 0 && ar[ed] != 1) ed--;
    if (ed < strt) {cout << 0 << endl; return 0;}
    for (int i{strt}; i<=ed; i++) {
        if (ar[i] == 1) {
            vals.push_back(cnt);
            cnt = 1;
        } else cnt++;
    }
    unsigned long long int ans{1};
    for (auto ele : vals) ans *= ele;
    cout << ans << endl;
    return 0;
}