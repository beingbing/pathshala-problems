#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m; // flowers Cnt, sub-array cnt
    vector<long long int> nums(n); // flower moods
    for (int i{0}; i<n; i++) cin>>nums[i];
    vector<long long int> cumSum(n);
    cumSum[0] = nums[0];
    for (int i{1}; i<n; i++) cumSum[i] = cumSum[i-1] + nums[i];
    vector<int> freq(n);
    int l, r;
    long long int val;
    while(m--) {
        cin>>l>>r;
        val = l != 1 ? cumSum[r-1] - cumSum[l-2] : cumSum[r-1];
        if (val > 0) for (int i{l}; i<=r; i++) freq[i-1]++;
    }
    long long int ans{0};
    for (int i{0}; i<n; i++) ans += (freq[i]*nums[i]);
    cout << ans << endl;
    return 0;
}