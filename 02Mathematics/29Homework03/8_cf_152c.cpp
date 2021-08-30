#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    int namesCnt, namesLen;
    cin >> namesCnt >> namesLen;
    vector<string> names(namesCnt);
    for (int i{0}; i<namesCnt; i++) cin >> names[i];
    set<char> candidates;
    const unsigned long long int m{1000000007};
    unsigned long long int ans{1};
    for (int j{0}; j<namesLen; j++) {
        for (int i{0}; i<namesCnt; i++)
            candidates.insert(names[i][j]);
        ans = ((ans%m) * (candidates.size()%m))%m;
        candidates.clear();
    }
    cout << ans << endl;
    return 0;
}