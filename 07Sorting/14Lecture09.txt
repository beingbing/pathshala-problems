~~ maximize the index difference ~~

given int arr, find two arr indexes i and j such that a[i] =< a[j] and j-i is maximum possible,
here i != j

M1-
for (int i{0}; i<n; i++) {
    for (int j{0}; j<n; j++) {
        if (j != i and a[j] >= a[i])
            ans = max(ans, j-i);
    }
}


M2 -

bool cmpr(pair<int, int> x, pair<int, int> y) {
    if (x.first != y.first) return x.first < y.first
    else return x.second < y.second
}

vec<pair<int, int>> v
for (int i{0}; i<n; i++)
    v.push_back({a[i], i});
sort(v.begin, v.end(), cmpr);
int ans = INT_MIN, sufMaxIdx = v[n-1].second
for (i{n-2}; i>=0; i--) {
    ans = max(ans, sufMaxIdx-vec[i].second)
    sufMaxIdx = max(sufMaxIdx, vec[i].second)
}

TC = O(nlogn)
SC = O(n)
