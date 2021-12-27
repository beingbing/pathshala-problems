#include <iostream>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    int tour(petrolPump p[], int n) {
        int totalSurplus = 0, curSurplus = 0, startingPoint = 0;
        for (int i{0}; i<n; i++) {
            totalSurplus += p[i].petrol - p[i].distance;
            curSurplus += p[i].petrol - p[i].distance;
            if (curSurplus < 0) {
                curSurplus = 0;
                startingPoint = i+1;
            }
        }
        return (totalSurplus < 0) ? -1 : startingPoint;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++) cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}
