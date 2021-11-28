#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> temps(200001, 0);
    int l, r;
    for (int i{0}; i<n; i++) {
        cin >> l >> r;
        temps[r]++;
        temps[l-1]--;
    }
    for (int i = 200001 - 2; i >= 0; i--) temps[i] = temps[i] + temps[i + 1];
    vector<int> pfSum(200001, 0); // if temps[i] >= k then consider them.
    for (int i{1}; i<200001; i++) {
        if (temps[i] >= k) pfSum[i] = pfSum[i-1] + 1;
        else pfSum[i] = pfSum[i-1];
    }
    int a, b;
    for (int i{0}; i<q; i++) {
        cin >> a >> b;
        cout << pfSum[b] - pfSum[a-1] << endl;
    }
    return 0;
}
