#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    bool subArrayExists(int arr[], int n) {
        int pfSum[n];
        pfSum[0] = arr[0];
        for (int i{1}; i<n; i++) pfSum[i] = pfSum[i-1] + arr[i];
        unordered_map<int ,int> mp;
        for (int i{0}; i<n; i++) {
            if (pfSum[i] == 0 && i != 0) return true;
            if (mp.find(pfSum[i]) != mp.end()) return true;
            mp[pfSum[i]] = i;
        }
        return false;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    Solution obj;
	    if (obj.subArrayExists(arr, n)) cout << "Yes\n";
	    else cout << "No\n";
	}
	return 0;
}
