#include <iostream>
#include <vector>
using namespace std;

int distancesum(vector<int>& a, int& n) {
	sort(a.begin(), a.end());
	int ans = 0, preSum = 0;
	for (int i = 0; i < n; i++) {
		ans += (a[i] * i - preSum); // prefix sum from 0 till i-1
		preSum += a[i];
	}
	return ans;
}

int totaldistancesum(vector<int>& x, vector<int>& y, int n) {
	return distancesum(x, n) + distancesum(y, n);
}

int main() {
	vector<int> x = { -1, 1, 3, 2 };
	vector<int> y = { 5, 6, 5, 3 };
	cout << totaldistancesum(x, y, 4) << endl;
	return 0;
}
