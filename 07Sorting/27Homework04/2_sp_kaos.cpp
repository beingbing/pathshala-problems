#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {
    ll cnt{0};

    void merge(vector<ll>& a, ll& s1, ll& e1, ll& e2) {
        ll s2{e1+1};
        ll i = s1, j = s2, c = s1;
        ll tmp[e2+1];
        while (i <= e1 && j <= e2) {
            if (a[i] <= a[j]) tmp[c++] = a[i++];
            else tmp[c++] = a[j++], cnt += e1 - i + 1;
        }
        while (i <= e1) tmp[c++] = a[i++];
        while (j <= e2) tmp[c++] = a[j++];
        for (i=s1; i<=e2; i++) a[i] = tmp[i];
    }

    void mergeSort(vector<ll>& a, ll l, ll r) {
        if (l == r) return;
        ll m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }

public:
    ll inversionCount(vector<ll>& ar, ll n) {
        mergeSort(ar, 0, n-1);
        return cnt;
    }
};

int main() {
    ll n;
    cin >> n;
    vector<string> words(n);
    for (ll i{0}; i<n; i++) cin >> words[i];
    sort(words.begin(), words.end());
    unordered_map<string, ll> wordsMap;
    for (ll i{0}; i<n; i++) wordsMap.insert({words[i], i+1});
    vector<string> revWords;
    for (auto ele : words) {
        reverse(ele.begin(), ele.end());
        revWords.push_back(ele);
    }
    sort(revWords.begin(), revWords.end());
    vector<ll> revAr;
    for (auto ele : revWords) {
        reverse(ele.begin(), ele.end());
        revAr.push_back(wordsMap[ele]);
    }
    Solution obj;
    cout << obj.inversionCount(revAr, n) << endl;
    return 0;
}
