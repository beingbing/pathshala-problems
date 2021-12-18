// from a given point, if two points have different slopes then these 3 points can form a triangle
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i{0}; i < n; i++) cin >> x[i] >> y[i];
    int cnt{0};
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if ((y[i] - y[j]) * (x[i] - x[k]) != (y[i] - y[k]) * (x[i] - x[j]))
                    cnt++;
    cout << cnt;
    return 0;
}
