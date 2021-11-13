#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long int cnt = 0;
long long int l, r;

void helper(long long int n, long long int lft, long long int rgt) {
    if (rgt < lft) return;
    long long int mid = lft + (rgt-lft)/2;
    if (lft == mid) {
        if (n == 1 && l <= mid && mid <= r) cnt++;
        return;
    }
    if (lft > r || rgt < l) return;
    helper(n / 2, lft, mid-1);
    helper(n % 2, mid, mid);
    helper(n / 2, mid+1, rgt);
}

int main() {
    long long int n;
    cin >> n >> l >> r;
    long long int len = 1;
    long long int x = log2(n);
    for (int i = 0; i < x; i++) len = len * 2 + 1;
    long long int mid = len/2 + 1;
    helper(n/2, 1, mid-1);
    helper(n%2, mid, mid);
    helper(n/2, mid+1, len);
    cout << cnt << endl;
    return 0;
}
