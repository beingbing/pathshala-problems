#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

vector<ll> transformation;

bool transform(ll a, ll& b) {
    if (a == b) return true;
    if (a > b) return false;
    a *= 2;
    transformation.push_back(a);
    bool res = transform(a, b);
    if (res) return res;
    transformation.pop_back();
    a /= 2;
    a = 10*a + 1;
    transformation.push_back(a);
    res = transform(a,b);
    if (res) return res;
    transformation.pop_back();
    a = (a-1)/10;
    return false;
}

int main() {
    ll a, b;
    cin >> a >> b;
    bool possible = false;
    transformation.push_back(a);
    possible = transform(a,b);
    cout << (possible ? "YES" : "NO") << endl;
    if (possible) {
        cout << transformation.size() << endl;
        for (auto ele : transformation) cout << ele << '\t';
    }
    return 0;
}