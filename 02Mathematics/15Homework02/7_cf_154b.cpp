#include <iostream>
#include <vector>
using namespace std;

void createSPFList(vector<int> &spf, const int &collidersCnt) {
    for (int i = 2; i <= collidersCnt; ++i)
        if (spf[i] == 0)
            for (int j = i; j <= collidersCnt; j += i)
                if (spf[j] == 0) spf[j] = i;
}

// cd = (common divisor > 1)
int checkConflict(const int &collider, vector<int> &spf, vector<int> &divisors) {
    for (int j = collider; j > 1; j /= spf[j])
        if (divisors[spf[j]] != 0)
            return j;
    return 1;
}

void setDivisors(const int &collider, vector<int> &spf, vector<int> &divisors) {
    for (int j = collider; j > 1; j /= spf[j]) divisors[spf[j]] = collider;
}

void unsetDivisors(const int &collider, vector<int> &spf, vector<int> &divisors) {
    for (int j = collider; j > 1; j /= spf[j]) divisors[spf[j]] = 0;
}

int main() {
    int collidersCnt, queriesCnt;
    cin >> collidersCnt >> queriesCnt;
    vector<int> spf(collidersCnt + 1, 0), divisors(collidersCnt + 1, 0);
    vector<bool> collidersStatus(collidersCnt + 1, false);
    createSPFList(spf, collidersCnt);
    while (queriesCnt--) {
        char action;
        int collider;
        cin >> action >> collider;
        if (action == '+') {
            if (collidersStatus[collider])
                cout << "Already on" << endl;
            else {
                int gcd = checkConflict(collider, spf, divisors);
                if (gcd == 1) {
                    collidersStatus[collider] = true;
                    setDivisors(collider, spf, divisors);
                    cout << "Success" << endl;
                }
                else
                    cout << "Conflict with " << divisors[spf[gcd]] << endl;
            }
        } else {
            if (collidersStatus[collider]) {
                collidersStatus[collider] = false;
                unsetDivisors(collider, spf, divisors);
                cout << "Success" << endl;
            } else cout << "Already off" << endl;
        }
    }
    return 0;
}