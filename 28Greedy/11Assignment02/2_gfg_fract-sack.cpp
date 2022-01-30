#include <iostream>
#include <iomanip>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {

    static bool Comp(Item& a, Item& b) {
        return a.value*b.weight > b.value*a.weight;
    }

public:
    double fractionalKnapsack(int w, Item a[], int n) {
        sort(a, a + n, Comp);
        double ans;
        for (int i{0}; i<n; i++) {
            if (w - a[i].weight >= 0) {
                ans += a[i].value;
                w -= a[i].weight;
            } else {
                double val = (w * a[i].value * 1.0) / a[i].weight;
                ans += val;
                break;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--) {
        int n, W;
        cin >> n >> W;
        Item arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i].value >> arr[i].weight;
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
