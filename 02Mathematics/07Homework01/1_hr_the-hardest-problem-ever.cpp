#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// if GCD of array is != 1 then the subarray with all the elements will make our answer 0
// if GCD of array is 1 then 1^1^1^.... (all 1's) = 1.
// so, if there is a non 1 GCD of given array, answer is 0, otherwise 1.

int findGCDM2(int a, int b) {
    int x = min(a, b);
    int y = max(a, b);
    if (x == 0) return y;
    if (y%x == 0) return x;
    return findGCDM2(x, y%x);
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<long long int> a;
        long long int temp;
        for (int i{0}; i<n; i++) {
            scanf("%lld", &temp);
            a.push_back(temp);
        }
        long long int gcd = a[0];
        for (int i{1}; i<n; i++) gcd = findGCDM2(gcd, a[i]);
        if (gcd == 1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}