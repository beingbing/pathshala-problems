#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &dgtsList, int numLimit) {
        string numStr = to_string(numLimit);
        int numSz = numStr.size(), dgtsCnt = dgtsList.size(), ans = 0;
        for (int i = 1; i < numSz; ++i) ans += pow(dgtsCnt, i); // for every position we have all digits as option available
        for (int i = 0; i < numSz; ++i) {
            bool hasSameNum = false;
            for (string &d : dgtsList) {
                if (d[0] < numStr[i]) ans += pow(dgtsCnt, numSz - i - 1);
                else if (d[0] == numStr[i]) hasSameNum = true;
            }
            if (!hasSameNum) return ans;
        }
        return ans + 1;
    }
};

int main() {
    vector<string> dgts = {"1", "2", "6"};
    int num = 2536;
    Solution obj;
    cout << obj.atMostNGivenDigitSet(dgts, num) << endl;
    return 0;
}
