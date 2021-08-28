// codeforces problem link
// https://codeforces.com/problemset/problem/131/C

#include <iostream>
#include <vector>
using namespace std;

vector<vector<unsigned long long int>> vec;

void generate() {
    vector<unsigned long long int> row(1, 1);
    vec.push_back(row);
    row = {};
    for (unsigned long long int i{1}; i<=30; i++) {
        for (unsigned long long int j{0}; j<=i; j++)
            if (j == 0) row.push_back(vec[i-1][j]);
            else if (j == i) row.push_back(vec[i-1][j-1]);
            else row.push_back(vec[i-1][j-1]+vec[i-1][j]);
        vec.push_back(row);
        row = {};
    }
}

int main() {
    generate();
    int t;
    cin >> t;
    while (t--) {
        unsigned long long int n, m, x;
        cin >> n >> m >> x;
        unsigned long long int ans{0};
        for (unsigned long long int i{4}; i<x; i++) {
            if (i <= n && x-i <= m) ans += (vec[n][i]*vec[m][x-i]);
        }
        cout << ans << endl;
    }
    return 0;
}