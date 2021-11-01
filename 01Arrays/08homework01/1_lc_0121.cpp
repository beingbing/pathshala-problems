// Best time to buy and sell stock 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxSell(n);
        maxSell[n-1] = prices[n-1];
        for (int i{n-2}; i>=0; i--) maxSell[i] = max(maxSell[i+1], prices[i]);
        int ans{INT_MIN};
        for (int i{0}; i<n; i++) ans = max(ans, maxSell[i]-prices[i]);
        return ans;
    }
};
