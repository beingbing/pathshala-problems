#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<long long int>& eles, vector<char>& signs, long long int& ans, int signsIdx) {
    if (eles.size() > 1 && signsIdx == signs.size()) return;
    if (eles.size() == 1) {
        ans = min(ans, eles[0]);
        return;
    }
    for (int i{0}; i<eles.size(); i++) {
        for (int j{i+1}; j<eles.size(); j++) {
            for (int k{signsIdx}; k<signs.size(); k++) {
                long long int a = eles[i];
                long long int b = eles[j];
                if (signs[k] == '+') a = a+b;
                else a *= b;
                vector<long long int> newEles;
                for (int l{0}; l<eles.size(); l++) {
                    if (l != i && l != j) newEles.push_back(eles[l]);
                }
                newEles.push_back(a);
                helper(newEles, signs, ans, k+1);
            }
        }
    }
}

int main() {
    vector<long long int> eles(4);
    vector<char> signs(3);
    long long int ans = {LLONG_MAX};
    for (int i{0}; i<4; i++) cin >> eles[i];
    for (int i{0}; i<3; i++) cin >> signs[i];
    helper(eles, signs, ans, 0);
    cout << ans << endl;
    return 0;
}
