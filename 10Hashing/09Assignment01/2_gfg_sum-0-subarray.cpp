#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    bool subArrayExists(int arr[], int n) {
        unordered_map<int, int> mp;
        int pfSum{0};
        mp[pfSum] = -1;
        for (int i{0}; i<n; i++) {
            pfSum += arr[i];
            if (mp.find(pfSum) != mp.end()) return true;
            mp[pfSum] = i;
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
