#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n,0);
        for (int i{0}; i<n; i++) cin >> vec[i];
        vector<int> freq(61,0);
        for (auto ele : vec) freq[ele]++;
        sort(vec.begin(), vec.end(), [&](int x, int y) {
            if (freq[x] == freq[y]) return x < y;
            return freq[x] > freq[y];
        });
        for (auto ele : vec) cout << ele << " ";
        cout << endl;
    }
    
    return 0;
}
