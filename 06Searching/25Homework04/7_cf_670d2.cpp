#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    bool possible(vector<long long int>& wtNeeded, vector<long long int>& wtPresent, long long int xtra, long long int cookiesCnt) {
        long long int n = wtNeeded.size(), mpReq;
        for (long long int i{0}; i<n; i++) {
            mpReq = cookiesCnt*wtNeeded[i] - wtPresent[i];
            if (mpReq > 0) xtra -= mpReq;
            if (xtra < 0) break;
        }
        return xtra >= 0;
    }

    public:
        long long int maxCookies(vector<long long int>& wtNeeded, vector<long long int>& wtPresent, long long int& xtra) {
            long long int low = 0, high = *max_element(wtPresent.begin(), wtPresent.end()) + xtra, mid;
            while (low <= high) {
                mid = low + (high - low)/2;
                if (!possible(wtNeeded, wtPresent, xtra, mid)) high = mid - 1;
                else {
                    if (!possible(wtNeeded, wtPresent, xtra, mid+1)) break;
                    else low = mid+1;
                }
            }
            return mid;
        }
};

int main() {
    long long int ingredientsCnt, magicPowder;
    cin >> ingredientsCnt >> magicPowder;
    vector<long long int> ingredientsWtNeeded(ingredientsCnt, 0), ingredientsWtHas(ingredientsCnt, 0);
    for (long long int i{0}; i<ingredientsCnt; i++) cin >> ingredientsWtNeeded[i];
    for (long long int i{0}; i<ingredientsCnt; i++) cin >> ingredientsWtHas[i];
    Solution obj;
    cout << obj.maxCookies(ingredientsWtNeeded, ingredientsWtHas, magicPowder) << endl;
    return 0;
}
