#include <iostream>
#include <vector>
using namespace std;

vector<vector<unsigned long long int>> vec;
unsigned long long int m{1000000007};

void generate() {
    vector<unsigned long long int> row(1, 1);
    vec.push_back(row);
    row = {};
    for (unsigned long long int i{1}; i <= 1000; i++) {
        for (unsigned long long int j{0}; j <= i; j++)
            if (j == 0)
                row.push_back(vec[i - 1][j]);
            else if (j == i)
                row.push_back(vec[i - 1][j - 1]);
            else
                row.push_back(((vec[i - 1][j - 1] % m) + (vec[i - 1][j] % m)) % m);
        vec.push_back(row);
        row = {};
    }
}

int main() {
    generate();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 != 0) {
            cout << -1 << endl;
            continue;
        }
        cout << vec[n][n / 2] / (n / 2 + 1) << endl;
    }
    return 0;
}
