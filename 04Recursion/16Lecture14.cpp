// find power using recursion
// famously called fast exponentiation
#include <iostream>
using namespace std;

// tc = O(k)
int myPow1(int bas, int pow) {
    if (pow == 1) return bas;
    return bas * myPow1(bas, pow-1);
}

// tc = O(logk)
int myPow2(int bas, int pow) {
    if (pow == 0) return 1;
    // recursion stacks created
    int val = myPow2(bas, pow/2);
    // recursion while getting resolved
    if (pow%2 == 0) return val*val;
    return bas * val * val;
}

int main() {
    int ans = myPow2(2, 5);
    cout << ans << endl;
    return 0;
}

// in this problem, the left and right half is identical, so we just call one of those and assume
// the result of second to be the same hence, multiplying the result with itself to get answer.
// This is how, this problem is different from previous problem as there both results were different
// and completely independent of each other, hence, we needed to calculate both.
