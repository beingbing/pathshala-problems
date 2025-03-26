// we need to find a == b, so if a^a = a^b => a^b = 0, hence if we can find all the pairs (i, k)
// such that their pfXor is same then also our problem will be solved.
// this is M2
// below is M1 which is brute force, as constraints are very lenient so this solution also cleared
// all test cases.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size(), cnt{0};
        vector<int> pfXor(n+1,0);
        for (int i{1}; i<=n; i++) pfXor[i] = pfXor[i-1]^a[i-1];
        for (int i{1}; i<=n; i++) {
            for (int j{i+1}; j<=n; j++) {
                for (int k{j}; k<=n; k++) {
                    if ((pfXor[i-1]^pfXor[j-1]) == (pfXor[j-1]^pfXor[k])) cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> a = {2,3,1,6,7};
    Solution obj;
    cout << obj.countTriplets(a) << endl;
    return 0;
}