#include <iostream>
using namespace std;

long long int findGCDM2(int a, int b) {
    long long int x = min(a, b);
    long long int y = max(a, b);
    if (x == 0) return y;
    if (y%x == 0) return x;
    return findGCDM2(x, y%x);
}

long long int findLCMM2(long long int a, long long int b) {
    long long int gcd = findGCDM2(a, b);
    return (a*b)/gcd;
}

int main() {
    int t;
    cin >> t;
    long long int n,a,b,k;
    while (t--) {
        cin >> n >> a >> b >> k;
        long long int lcm = findLCMM2(a, b);
        long long int appy = n/a - n/lcm;
        long long int chef = n/b - n/lcm;
        if (appy + chef >= k) cout << "Win" << endl;
        else cout << "Lose" << endl;
    }
    return 0;
}