#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
 
    bool possible(vector<int>& wtNeeded, vector<int>& wtPresent, int xtra, int cookiesCnt) {
        int n = wtNeeded.size(), mpReq;
        for (int i{0}; i<n; i++) {
            mpReq = cookiesCnt*wtNeeded[i] - wtPresent[i];
            if (mpReq > 0) xtra -= mpReq;
        }
        return xtra >= 0;
    }
 
    public:
        int maxCookies(vector<int>& wtNeeded, vector<int>& wtPresent, int& xtra) {
            int low = 0, high = *max_element(wtPresent.begin(), wtPresent.end()) + xtra, mid;
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
    int ingredientsCnt, magicPowder;
    cin >> ingredientsCnt >> magicPowder;
    vector<int> ingredientsWtNeeded(ingredientsCnt, 0), ingredientsWtHas(ingredientsCnt, 0);
    for (int i{0}; i<ingredientsCnt; i++) cin >> ingredientsWtNeeded[i];
    for (int i{0}; i<ingredientsCnt; i++) cin >> ingredientsWtHas[i];
    Solution obj;
    cout << obj.maxCookies(ingredientsWtNeeded, ingredientsWtHas, magicPowder) << endl;
    return 0;
}
