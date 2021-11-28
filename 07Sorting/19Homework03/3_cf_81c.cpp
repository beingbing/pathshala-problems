#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<int> marks(n, 0);
    for (int i{0}; i<n; i++) cin >> marks[i];
    vector<pair<int, int>> vec;
    for (int i{0}; i<n; i++) vec.push_back({marks[i], i});
    sort(vec.begin(), vec.end(), [&](pair<int, int> &x, pair<int, int> &y) {
        if (x.first == y.first && a < b) return x.second < y.second;
        if (x.first == y.first && a > b) return x.second > y.second;
        return x.first > y.first;
    });
    vector<int> ans(n,0);
    if (a != b) {
        int k{1}, l{2}, p{a};
        if (a > b) k = 2, l = 1, p = b;
        for (int i{0}; i<p; i++) ans[vec[i].second] = k;
        for (int i{p}; i<n; i++) ans[vec[i].second] = l;
    } else {
        for (int i{0}; i<a; i++) ans[i] = 1;
        for (int i{a}; i<n; i++) ans[i] = 2;
    }
    for (auto ele : ans) cout << ele << " ";
    cout << endl;
    return 0;
}
