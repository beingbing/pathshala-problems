#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int firstPosition(vector<int> &nums, int &n, int &target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid-1;
        else if (nums[mid] < target) low = mid+1;
        else {
            if (mid == 0) return mid;
            else if (nums[mid-1] != target) return mid;
            else high = mid-1;
        }
    }
    return -1;
}

int lastPosition(vector<int> &nums, int &n, int &target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid-1;
        else if (nums[mid] < target) low = mid+1;
        else {
            if (mid == n-1) return mid;
            else if (nums[mid+1] != target) return mid;
            else low = mid+1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), lhsArr, rhsArr;
    for (int i{0}; i < n; i++) cin >> a[i];

    for (int i{0}; i < n; i++)
        for (int j{0}; j < n; j++)
            for (int k{0}; k < n; k++)
                lhsArr.push_back(a[i] * a[j] + a[k]);

    for (int i{0}; i < n; i++)
        for (int j{0}; j < n; j++)
            for (int k{0}; k < n; k++)
                if (a[k] != 0)
                    rhsArr.push_back((a[i] + a[j]) * a[k]);
    sort(rhsArr.begin(), rhsArr.end());
    int ans{0}, k = rhsArr.size();
    for (auto ele : lhsArr) {
        int frst = firstPosition(rhsArr, k, ele);
        int last = lastPosition(rhsArr, k, ele);
        if (frst == last && last == -1) continue;
        else ans += last-frst+1;
    }
    cout << ans << endl;
    return 0;
}
