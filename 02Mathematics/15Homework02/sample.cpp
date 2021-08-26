#include <iostream>
#include <vector>
using namespace std;

vector<int> spf(102400, 0), divisors(102400, 0);
int collidersCnt, queriesCnt, collider;
vector<bool> on(102400, false);
char action;

int main() {
    cin >> collidersCnt >> queriesCnt;
    for (int i = 2; i <= collidersCnt; ++i) if (spf[i] == 0) for (int j = i; j <= collidersCnt; j += i) spf[j] = i;
    while (queriesCnt--) {
        cin >> action >> collider;
        if (action == '+') {
            if (on[collider]) cout << "Already on" << endl;
            else {
                int j;
                for (j = collider; j > 1; j /= spf[j]) if (divisors[spf[j]] != 0) break;
                if (j == 1) {
                    on[collider] = 1;
                    for (j = collider; j > 1; j /= spf[j]) divisors[spf[j]] = collider;
                    cout << "Success" << endl;
                } else cout << "Conflict with " << divisors[spf[j]] << endl;
            }
        } else {
            if (on[collider]) {
                on[collider] = false;
                for (int j = collider; j > 1; j /= spf[j]) divisors[spf[j]] = 0;
                cout << "Success" << endl;
            } else cout << "Already off" << endl;
        }
    }
    return 0;
}