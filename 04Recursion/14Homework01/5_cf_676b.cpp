#include <iostream>
#include <vector>
using namespace std;

void fillGlasses(vector<vector<double>>& mat, int& n, int i, int j, double k) {
    if (i >= n || j >= n || j > i) return;
    mat[i][j] += k;
    if (mat[i][j] > 1) {
        double xtra = mat[i][j] - 1;
        mat[i][j] -= xtra;
        fillGlasses(mat, n, i+1, j, xtra*0.5);
        fillGlasses(mat, n, i+1, j+1, xtra*0.5);
    }
}

int main() {
    int n,t;
    cin >> n >> t;
    vector<vector<double>> mat(n, vector<double>(n, 0));
    int cnt = 0, tme = 0;
    for (int i{0}; i<t; i++) fillGlasses(mat, n, 0, 0, 1);
    for (int i{0}; i<n; i++) for (int j{0}; j<=i; j++) if (mat[i][j] == 1) cnt++;
    cout << cnt << endl;
    return 0;
}
