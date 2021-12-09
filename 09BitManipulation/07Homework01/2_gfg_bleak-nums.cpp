#include<iostream>
using namespace std;

class Solution {

    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }

public:
	int is_bleak(int n) {
	    for (int i{n-1}; i>0; i--) {
            if (i + hammingWeight(i) == n) return 0;
        }
        return 1;
	}
};

int main(){
    int T;
    cin >> T;
    while(T--) {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}
