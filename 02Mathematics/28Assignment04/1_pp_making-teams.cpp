// codeforces problem link
// https://codeforces.com/problemset/problem/131/C

#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long int ull;

vector<vector<ull>> vec;

void generatePascalTriangle() {
    vector<ull> row(1, 1);
    vec.push_back(row);
    row = {};
    for (ull i{1}; i<=30; i++) {
        for (ull j{0}; j<=i; j++)
            if (j == 0) row.push_back(vec[i-1][j]);
            else if (j == i) row.push_back(vec[i-1][j-1]);
            else row.push_back(vec[i-1][j-1]+vec[i-1][j]);
        vec.push_back(row);
        row = {};
    }
}

int main() {
    generatePascalTriangle();
    int t;
    cin >> t;
    while (t--) {
        ull n, m, x;
        cin >> n >> m >> x;
        ull ans{0};
        for (ull i{4}; i<x; i++) {
            if (i <= n && x-i <= m) ans += (vec[n][i]*vec[m][x-i]);
        }
        cout << ans << endl;
    }
    return 0;
}