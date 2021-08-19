// distinct paths from 0,0 to m,n with moment allowed only in right or bottom cell

#include <iostream>
using namespace std;

int m, n;

int countPaths(int i, int j) {
    if (i == m-1 || j == n-1) return 1;
    return countPaths(i+1,j) + countPaths(i, j+1);
}

int cnt{0};

void countPaths2(int i, int j) {
    if (i == m-1 || j == m-1) {
        cnt++;
        return;
    }
    countPaths2(i+1,j);
    countPaths2(i, j+1);
}

int countPaths3(int i, int j) {
    if (i == 0 || j == 0) return 1;
    return countPaths3(i-1, j) + countPaths3(i,j-1);
}

int main() {
    cin>>m>>n;
    int ans = countPaths(0,0);
    cout << ans << endl;
    return 0;
}