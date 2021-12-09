#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), carry{0}, cnt{0};
        for (int i{n-1}; i>0; i--) {
            if (s[i] == '1') {
                if (carry == 0) cnt += 2;
                else cnt++;
                carry = 1;
            } else {
                if (carry == 0) cnt++;
                else cnt += 2;
            }
        }
        if (carry == 1) cnt++;
        return cnt;
    }
};

int main() {
    string s = "111010001";
    Solution obj;
    cout << obj.numSteps(s) << endl;
    return 0;
}
