/*

You are given two numbers A and B.

Print two integers X and Y where X=GCD(A,B) and Y=LCM(A,B).

Input Format
Input consists of two space separated integers A and B.

Output Format
Print two Integers X and Y.

Constraints1≤A,B≤10^9

*/

#include <iostream>
using namespace std;

int findGCDM1(int a, int b) { // tc = O(n)
    int i = min(a, b);
    if (i == 0) return max(a,b);
    for (; i>1; i--) if (a%i == 0 and b%i == 0) return i;
    return 1;
}

// euclid's gcd algorithm - tc = O(logn)
// recursive
int findGCDM2(int a, int b) {
    int x = min(a, b);
    int y = max(a, b);
    if (x == 0) return y;
    if (y%x == 0) return x;
    return findGCDM2(y%x, x);
}

// iterative
int findGCDM2(int a, int b) {
    int x = min(a, b);
    int y = max(a, b);
    if (x == 0) return y;
    int tmp;
    while (y%x != 0) {
        tmp = y;
        y = x;
        x = tmp%y;
    }
    return x;
}

int findLCMM1(int a, int b) {
    int i = max(a, b), lim = a*b;
    for (; i<lim; i++) if (i%a == 0 and i%b == 0) return i;
    return a*b;
}

int findLCMM2(int a, int b) {
    int gcd = findGCDM2(a, b);
    return (a*b)/gcd;
}

int main(){
    cout << findLCMM2(12, 18) << endl;
    return 0;
}