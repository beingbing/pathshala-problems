#include <iostream>
using namespace std;

class Solution {
    double custPow(double bas, long int k) {
        if (k == 0) return 1;
        if (bas == 1) return bas;
        if (k < 0) return custPow(1/bas, -k);
        double val = custPow(bas, k/2);
        if (k%2 == 0) return val*val;
        return val*val*bas;
    }
public:
    double myPow(double x, int n) {
        return custPow(x, n);
    }
};