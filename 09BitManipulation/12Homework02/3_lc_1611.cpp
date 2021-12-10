// learn it, how to convert gray code element into its equivalent decimal place
#include <iostream>
using namespace std;

class Solution {
    
public:
    int minimumOneBitOperations(int ele) {
        int ans = 0;
        while (ele > 0) {
            ans ^= ele;
            ele = ele >> 1;
        }
        return ans;
    }
};

int main() {
    int n = 9;
    Solution obj;
    cout << obj.minimumOneBitOperations(n) << endl;
    return 0;
}
