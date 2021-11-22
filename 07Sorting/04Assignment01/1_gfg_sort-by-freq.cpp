// method 1 (inline comparator)
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> vec(n,0);
//         for (int i{0}; i<n; i++) cin >> vec[i];
//         vector<int> freq(61,0);
//         for (auto ele : vec) freq[ele]++;
//         sort(vec.begin(), vec.end(), [&](int x, int y) {
//             if (freq[x] == freq[y]) return x < y;
//             return freq[x] > freq[y];
//         });
//         for (auto ele : vec) cout << ele << " ";
//         cout << endl;
//     }
    
//     return 0;
// }

// method 2 (comparator with class/struct)
#include <iostream>
#include <vector>
using namespace std;

struct triplet {
    int val, freq, idx;
};

bool cmpr(triplet t1, triplet t2) {
    if (t1.freq != t2.freq) return t1.freq > t2.freq;
    if (t1.val != t2.val) return t1.val < t2.val;
    return t1.idx < t2.idx;
}

vector<triplet> constructTriplet(int& n, vector<int>& vec, vector<int>& freq) {
    vector<triplet> v;
    for (int i = 0; i < n; i++) {
        triplet tri;
        tri.val = vec[i];
        tri.freq = freq[vec[i]];
        tri.idx = i;
        v.push_back(tri);
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n, 0), freq(61, 0);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            freq[vec[i]]++;
        }
        vector<triplet> v = constructTriplet(n, vec, freq);
        sort(v.begin(), v.end(), cmpr);
        for (auto ele : v) cout << ele.val << " ";
        cout << endl;
    }
    return 0;
}
