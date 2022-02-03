#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cur, ans{0}, prv{0};
    for (int i{0}; i < n; i++) {
        cin >> cur;
        if (cur == 0 || (cur == 1 && prv == 1) || (cur == 2 && prv == 2)) {
            prv = 0;
            ans++;
        } else {
            if (cur == 3) {
                if (prv == 1) prv = 2;
                else if (prv == 2) prv = 1;
                else prv = 3;
            } else prv = cur;
        }
    }
    cout << ans << endl;
    return 0;
}
