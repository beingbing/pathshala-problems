#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(), x{0};
        for (int i{1}; i<=n+1; i++) x = x^i;
        vector<int> prem(n+1, 0);
        prem[0] = x;
        for (int i{1}; i<n; i++) if(i%2 != 0) prem[0] ^= encoded[i];
        for (int i{1}; i<n+1; i++) prem[i] = prem[i-1]^encoded[i-1];
        return prem;
    }
};

int main() {
    vector<int> encoded = {6,5,4,6};
    Solution obj;
    vector<int> ans = obj.decode(encoded);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}
