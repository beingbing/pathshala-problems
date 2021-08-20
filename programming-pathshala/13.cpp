// find power using recursion

#include <iostream>
using namespace std;

// tc = O(k)
int myPow1(int bas, int pow) {
    if (pow == 1) return bas;
    return bas * myPow1(2, pow-1);
}

// tc = O(logk)
int myPow2(int bas, int pow) {
    if (pow == 0) return 1;
    int val = myPow2(bas, pow/2);
    if (pow%2 == 0) return val*val;
    return bas * val * val;
}

int main() {
    int ans = myPow2(2, 5);
    cout << ans << endl;
    return 0;
}