#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> separateSortEvenOddIndices(vector<int> &a, int n) {
    vector<int> oddAr, evenAr, tsorted;
    for (int i{0}; i < n; i++)
        if (i % 2 == 0) evenAr.push_back(a[i]);
        else oddAr.push_back(a[i]);
    sort(oddAr.begin(), oddAr.end());
    sort(evenAr.begin(), evenAr.end());
    int eIdx = 0;
    int oIdx = 0;
    for (int idx = 0; idx < (evenAr.size() + oddAr.size()); idx++) {
        if (idx % 2 == 0) {
            tsorted.push_back(evenAr[eIdx]);
            eIdx++;
        } else {
            tsorted.push_back(oddAr[oIdx]);
            oIdx++;
        }
    }
    return tsorted;
}

int main() {
    int t{0}, T;
    cin >> T;
    while (t < T) {
        t++;
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i{0}; i < n; i++) cin >> a[i];
        bool flag = false;
        int ans{0};
        vector<int> ta = separateSortEvenOddIndices(a, n);
        sort(a.begin(), a.end());
        for (int i{0}; i < n; i++) {
            if (a[i] != ta[i]) {
                flag = true;
                ans = i;
                break;
            }
        }
        if (flag) cout << "Case #" << t << ": " << ans << endl;
        else cout << "Case #" << t << ": OK" << endl;
    }
    return 0;
}
