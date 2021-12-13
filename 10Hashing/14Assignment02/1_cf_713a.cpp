#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

ll getnum(string a) {
    int len = a.length();
    int num = 0;
    int cnt = 1;
    for (int i = len - 1; i >= 0; i--) {
        num += ((a[i] - '0') % 2) * cnt;
        cnt *= 2;
    }
    return num;
}

int main() {
    unordered_map<int, int> transformedNumsCnt;
    ll t;
    cin >> t;
    while (t--) {
        string ch, num;
        cin >> ch >> num;
        ll ele = getnum(num);
        if (ch == "+") transformedNumsCnt[ele]++;
        else if (ch == "-") transformedNumsCnt[ele]--;
        else cout << transformedNumsCnt[ele] << endl;
    }
    return 0;
}
