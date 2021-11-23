#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmpr(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i{0}; i<n; i++) cin >> vec[i];
    vector<pair<int, int>> pos;
    for (int i{0}; i<n; i++) pos.push_back({vec[i], i});
    sort(pos.begin(), pos.end(), cmpr);
    for (auto ele : pos) cout << ele.second+1 << " ";
    cout << endl;
    return 0;
}
