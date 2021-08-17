/*
given a number return false if it has even number of divisor,
otherwise return true
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int val = sqrt(n);
    if (val*val == n) cout << 'true' << endl;
    else cout << 'false' << endl; 
    return 0;
}