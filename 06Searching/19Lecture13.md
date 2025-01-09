~~ maximize k ~~

given an unsorted array with positive elements only.
given x >= 0.
Find maximum possible k such that none of the subarray of size k has a sum > x.

subarray -> contiguous chunk of an array

sum(subarray of size k) <= x        required, give such a k and it's value must be maximum possible


This problem has a monotonous function possible on the size of array considered.
e.g. - if a subarray has sum >x, then decresease it's size (go to left)
and vice versa.

so, our domain will be size of array

bool isPossible(vector<int>& v, int& m, int& x) {
    int n = v.size();
    if (m >= n) return false;
    int sum{0};
    for (int i{0}; i<m; i++) sum += v[i];
    for (int i{m}; i<n; i++) {
        if (sum > x) return false;
        sum += v[i];
        sum -= v[i-k];
    }
    if (sum > x) return false;
    return true;
}
TC= O(n)

l = 0, h = n;
while (l <= h) {
    m = (l+h)/2;
    if (!isPossible(v, m, x)) h = m-1;
    else {
        if (!isPossible(v, m+1, x)) return m;
        else l = m+1;
    }
}
TC = O(nlogn)