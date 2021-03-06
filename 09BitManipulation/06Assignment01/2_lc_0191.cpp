#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
};

int main() {
    uint32_t n;
    cin >> n;
    Solution obj;
    cout << obj.hammingWeight(n) << endl;
    return 0;
}
