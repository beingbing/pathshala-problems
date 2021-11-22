#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long int calculateCost(vector<int>& baseCost, int i) {
    vector<int> aux;
    for (int j{0}; j<baseCost.size(); j++) aux.push_back(baseCost[j] + (j+1)*i);
    sort(aux.begin(), aux.end());
    int k{0};
    long long int cost{0};
    while (k < i) cost += aux[k++];
    return cost;
}
 
int main() {
    int souvenirCnt, budget, i;
    cin >> souvenirCnt >> budget;
    vector<int> baseCost(souvenirCnt, 0);
    for (i = 0; i<souvenirCnt; i++) cin >> baseCost[i];
    for (i = 1; i<=souvenirCnt; i++) if (calculateCost(baseCost, i) > budget) break;
    cout << i-1 << " " << calculateCost(baseCost, i-1) << endl;
    return 0;
}
