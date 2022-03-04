// codeforces problem link
// https://codeforces.com/contest/1034/problem/A

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int calcGCD(int a, int b) {
    int x = min(a, b);
    int y = max(a, b);
    if (x == 0) return y;
    if (y % x == 0) return x;
    return calcGCD(y % x, x);
}

vector<int> spf(15000001, 0);

void createSPFList() {
    for (int i = 2; i <= 15000000; ++i)
        if (spf[i] == 0)
            for (int j = i; j <= 15000000; j += i)
                if (spf[j] == 0) spf[j] = i;
}

int main() {
    createSPFList();
    int n;
    cin >> n;
    vector<int> nums(n);
    int gcd = 0;
    for (int i{0}; i < n; i++) {
        cin >> nums[i];
        gcd = calcGCD(gcd, nums[i]);
    }
    map<int, int> primesFreq;
    for (int i{0}; i < n; i++) {
        nums[i] /= gcd;
        while (spf[nums[i]] != 0) {
            primesFreq[spf[nums[i]]]++;
            int val = nums[i];
            while (nums[i] % spf[val] == 0) nums[i] /= spf[val];
        }
    }
    int mx{0};
    for (auto ele : primesFreq) mx = max(ele.second, mx);
    cout << (mx ? n - mx : -1) << endl;
    return 0;
}