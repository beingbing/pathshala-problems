#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> idxPfXor(n + 1, 0);
    for (int i{1}; i <= n; i++) idxPfXor[i] = idxPfXor[i - 1] ^ i;
    int Q = 0, temp;
    for (int i{0}; i < n; i++) {
        cin >> temp;
        Q ^= temp;
    }
    for (int i{1}; i <= n; i++) Q ^= idxPfXor[n % i] ^ (((n / i) % 2) * idxPfXor[i - 1]);
    cout << Q << endl;
    return 0;
}
