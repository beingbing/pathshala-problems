/*

optimal substructure =>  table[i] = table[i] + table[i - 3] + table[i - 5] + table[i - 10]

    0
    3                           5                           10
    3       5       10          5           10              10
    3 5 10  5 10    10          5   10      10              10
*/

#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

ll count(ll n) {
    ll table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    vector<int> vec = {3,5,10};
    for (int j{0}; j<3; j++)
        for (i = vec[j]; i <= n; i++) table[i] += table[i-vec[j]];
    return table[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}
