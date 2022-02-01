/*

optimal substructure =>  table[i] = table[i] + table[i - 3] + table[i - 5] + table[i - 10]

    0
    3                           5                           10
    3       5       10          5           10              10
    3 5 10  5 10    10          5   10      10              10
*/

#include <iostream>
using namespace std;
#define ll long long int

ll count(ll n) {
    ll table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (i = 3; i <= n; i++) table[i] = table[i-3];
    for (i = 5; i <= n; i++) table[i] = table[i-5];
    for (i = 10; i <= n; i++) table[i] = table[i-10];
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
