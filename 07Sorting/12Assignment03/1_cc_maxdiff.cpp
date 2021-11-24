#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, sum{0};
        cin >> n >> k;
        vector<int> vec(n);
        for (int i{0}; i<n; i++) cin >> vec[i], sum += vec[i];
        sort(vec.begin(), vec.end());
        int son{0};
        for (int i{0}; i<k; i++) son += vec[i];
        int fath{0};
        for (int i{0}; i<n-k; i++) fath += vec[i];
        if (abs(sum - (2*son)) > abs(sum - (2*fath))) cout << abs(sum - (2*son)) << endl;
        else cout << abs(sum - (2*fath)) << endl;
    }
    return 0;
}
