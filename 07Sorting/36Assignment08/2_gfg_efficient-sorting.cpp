#include <iostream>
using namespace std;

class Solution{
    public:
    void sort(int a[], int n)
    {
        int cnt[n], aux[n];
        for (int i{0}; i<n; i++) cnt[i] = 0;
        for (int i{0}; i<n; i++) cnt[a[i]%n]++;
        for (int i{1}; i<n; i++) cnt[i] += cnt[i-1];
        for (int i{n-1}; i>=0; i--) {
            aux[cnt[a[i]%n]-1] = a[i];
            cnt[a[i]%n]--;
        }
        for (int i{0}; i<n; i++) {
            a[i] = aux[i];
            cnt[i] = 0;
        }
        for (int i{0}; i<n; i++) cnt[(a[i]/n)%n]++;
        for (int i{1}; i<n; i++) cnt[i] += cnt[i-1];
        for (int i{n-1}; i>=0; i--) {
            aux[cnt[(a[i]/n)%n]-1] = a[i];
            cnt[(a[i]/n)%n]--;
        }
        for (int i{0}; i<n; i++) {
            a[i] = aux[i];
            cnt[i] = 0;
        }
        for (int i{0}; i<n; i++) cnt[((a[i]/n)/n)%n]++;
        for (int i{1}; i<n; i++) cnt[i] += cnt[i-1];
        for (int i{n-1}; i>=0; i--) {
            aux[cnt[((a[i]/n)/n)%n]-1] = a[i];
            cnt[((a[i]/n)/n)%n]--;
        }
        for (int i{0}; i<n; i++) a[i] = aux[i];
    }
};

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}


int main() {
    int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) cin >> arr[i];
		Solution ob;
		ob.sort (arr, n);
		print (arr, n);
		cout << endl;
	}
}
