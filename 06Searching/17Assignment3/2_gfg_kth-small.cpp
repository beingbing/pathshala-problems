#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallest(vector<int>& arr, int k, int n) {
	int low = *min_element(arr.begin(), arr.end());
	int high = *max_element(arr.begin(), arr.end());
	while (low <= high) {
		int mid = low + (high - low) / 2;
		int countless = 0, countequal = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] < mid) ++countless;
			else if (arr[i] == mid) ++countequal;
		}
		if (countless < k && (countless + countequal) >= k) return mid;
		else if (countless >= k) high = mid - 1;
		else if (countless < k && countless + countequal < k) low = mid + 1;
	}
}

int countNums(vector<int>& a, int x, int &n) {
    int cnt = 0;
    for (int i{0}; i<n; i++) if (a[i] <= x) cnt++;
    return cnt;
}

int kthSmallestM2(vector<int>& arr, int k, int n) {
    int low = *min_element(arr.begin(), arr.end());
	int high = *max_element(arr.begin(), arr.end());
    while (low <= high) {
        int mid = low + (high-low)/2;
        int cnt = countNums(arr, mid, n);
        if (cnt < k) low = mid+1;
        else {
            int cnt1 = countNums(arr, mid-1, n);
            if (cnt1 < k) return mid;
            else high = mid-1;
        }
    }
}

int main() {
	vector<int> arr = { 7, 10, 4, 3, 20, 15 };
	int n = arr.size();
	int k = 3;
	cout << kthSmallest(arr, k, n) << endl;
    cout << kthSmallestM2(arr, k, n) << endl;
	return 0;
}
