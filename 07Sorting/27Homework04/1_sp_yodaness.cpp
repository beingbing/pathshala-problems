#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    long long cnt{0};

    void merge(vector<long long>& a, long long& s1, long long& e1, long long& e2) {
        long long s2{e1+1};
        long long i = s1, j = s2, c = s1;
        long long tmp[e2+1];
        while (i <= e1 && j <= e2)
            if (a[i] < a[j]) tmp[c++] = a[i++];
            else tmp[c++] = a[j++], cnt += e1 - i + 1;
        while (i <= e1) tmp[c++] = a[i++];
        while (j <= e2) tmp[c++] = a[j++];
        for (i=s1; i<=e2; i++) a[i] = tmp[i];
    }

    void mergeSort(vector<long long>& a, long long l, long long r) {
        if (l == r) return;
        long long m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }

public:
    long long inversionCount(vector<long long>& ar, long long n) {
        mergeSort(ar, 0, n-1);
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> yodaWords(n), normalWords(n);
        for (int i{0}; i<n; i++) cin >> yodaWords[i];
        for (int i{0}; i<n; i++) cin >> normalWords[i];
        unordered_map<string, int> wordsMap;
        for (int i{0}; i<n; i++) wordsMap.insert({normalWords[i], i+1});
        vector<long long> yodaRank(n);
        for (int i{0}; i<n; i++) yodaRank[i] = (long long) wordsMap[yodaWords[i]];
        Solution obj;
        cout << obj.inversionCount(yodaRank, n) << endl;
    }
    return 0;
}
