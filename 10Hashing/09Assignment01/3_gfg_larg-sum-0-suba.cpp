#include <iostream>
#include <unordered_map>
using namespace std;

int maxLen(int arr[], int n) {
    unordered_map<int, int> mp;
    int ans = 0, psum = 0;
    mp[psum] = -1;
    for (int i = 0; i < n; i++) {
        psum += arr[i];
        if (mp.find(psum) == mp.end()) mp[psum] = i;
        else ans = max(ans, i - mp[psum]);
    }
    return ans;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = 8;
    cout << "Length of the longest 0 sum subarray is " << maxLen(arr, n);
    return 0;
}
