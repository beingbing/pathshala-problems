/*

optimal substructure => minCost[i] = min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2])
(recursive relation)

*/
#include <vector>
using namespace std;

class Solution {

    int minmCost(int n, vector<int>& cost, vector<int>& memo) {
        if (n <= 1) return 0;
        if (memo[n] == 0)
            memo[n] = min(minmCost(n-1, cost, memo) + cost[n-1], minmCost(n-2, cost, memo) + cost[n-2]);
        return memo[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(n+1, 0);
        for (int i{2}; i<=n; i++)
            minCost[i] = min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
        return minCost[n];
    }

    int minCostClimbingStair2(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n+1, 0);
        return minmCost(n, cost, memo);
    }
};
