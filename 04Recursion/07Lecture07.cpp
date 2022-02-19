// ~~ distinct paths 1 ~~

// rat in the maze problem

#include <iostream>
using namespace std;

int m, n;

int countPaths(int i, int j) {
    if (i == m - 1 || j == n - 1) return 1;
    return countPaths(i + 1, j) + countPaths(i, j + 1);
}

int main() {
    cin >> m >> n;
    int ans = countPaths(0, 0);
    cout << ans << endl;
    return 0;
}

// TC = (2^(m+n))
// SC =
