#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string str) {
        long long int n = stoll(str);
        for (int i{63}; i>=1; i--) {
            long long int l = 2, h = n - 1;
            while (l <= h) {
                long long int m = l + (h - l)/2;
                long long int sum = 0, x = 1;
                bool flag = false;
                for (int j{0}; j<=i; j++) {
                    sum += x;
                    if (sum >= n) break;
                    if (j < i && (n-sum)/x < m) {
                        flag = true;
                        break;
                    }
                    if (j < i) x *= m;
                }
                if (sum > n || flag) h = m-1;
                else if (sum < n) l = m+1;
                else return to_string(m);
            }
        }
        return "2";
    }
};

int main() {
    Solution obj;
    cout << obj.smallestGoodBase("1000000000000000000") << endl;
    return 0;
}
