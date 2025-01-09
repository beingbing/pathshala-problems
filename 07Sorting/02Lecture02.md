# custom comparators

Problem 1: given n coordinates, find k closest points from origin.
so, 
bool cmpr(int x, int y) {
    return x.first*x.first + x.second*x.second < y.first*y.first + y.second*y.second;
}

Problem 2: given array a, such that 0 <= a[i] <= 100.
- sort such that smallest frequency element comes first.
- if same frequency, smallest value element should come first.
- if value also same, then element with smaller index should come first.

struct triplet {
    int val, freq, idx;
}

vector<int> freq(101, 0);
for (int i{0}; i<n; i++) freq[a[i]]++;
vector<triplet> v;
for (int i{0}; i<n; i++) {
    triplet t;
    t.val = a[i];
    t.freq = freq[a[i]];
    t.idx = i;
    v.push_back(t);
}
bool cmpr(triplet x, triplet y) {
    if (x.freq != y.freq) return x.freq < y.freq;
    else if (x.val != y.val) return x.val < y.val;
    else x.idx < y.idx;
}
sort(v.begin(), v.end(), cmpr);
