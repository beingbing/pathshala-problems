#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:	
	bool hasArrayTwoCandidates(int a[], int n, int k) {
	    unordered_map<int, int> mp;
	    for (int i{0}; i<n; i++) {
	        if (mp.find(k - a[i]) != mp.end()) return true;
	        mp[a[i]] = i;
	    }
        return false;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
