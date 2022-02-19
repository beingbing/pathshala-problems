// ~~ distinct paths: Alternate Implementation ~~
// distinct paths from 0,0 to m,n with moment allowed only in right or bottom cell
// state: current value of an argument

#include <iostream>
using namespace std;

int m, n, cnt{0};

// when function to use global variables and to abide by void function signature
// then modify your code of previous lecture like this
void countPaths2(int i, int j) {
    if (i == m - 1 || j == m - 1) {
        cnt++;
        return;
    }
    countPaths2(i + 1, j);
    countPaths2(i, j + 1);
}

// bottom to top recursion
// another way to approach this problem
int countPaths3(int i, int j) {
    if (i == 0 || j == 0) return 1;
    return countPaths3(i - 1, j) + countPaths3(i, j - 1);
}

int main() {
    cin >> m >> n;
    countPaths2(0, 0);
    cout << cnt << endl;
    return 0;
}
