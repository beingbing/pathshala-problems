// { Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

vector<long long> sortArray(vector<long long> arr, int n, long long A, long long B, long long C);

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int a, b, c;
        cin >> a >> b >> c;
        int n;
        cin >> n;
        vector<long long int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<long long int> ans = sortArray(arr, n, a, b, c);
        for (int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}

vector<long long> sortArray(vector<long long> ar, int n, long long a, long long b, long long c) {
    long long int i = 0;
    vector<long long int> ans;
        for (;i < n; i++) if (ar[i] >= (-1 * b) / (2*a)) break;
        long long int j = i-1;
    if (a >= 0) {
        while (j >= 0 and i < n) {
            if (((a*ar[i]*ar[i]) + (b*ar[i]) + c) <= ((a*ar[j]*ar[j]) + (b*ar[j]) + c)) {
                ans.push_back(((a*ar[i]*ar[i]) + (b*ar[i]) + c));
                i++;
            } else {
                ans.push_back(((a*ar[j]*ar[j]) + (b*ar[j]) + c));
                j--;
            }
        }
        while (j >= 0) ans.push_back((a*ar[j]*ar[j]) + (b*ar[j]) + c), j--;
        while (i < n) ans.push_back(((a*ar[i]*ar[i]) + (b*ar[i]) + c)), i++;
    } else {
        long long int k = 0, l = n-1;
        while (k <= j and i <= l) {
            if (((a*ar[k]*ar[k]) + (b*ar[k]) + c) <= ((a*ar[l]*ar[l]) + (b*ar[l]) + c)) {
                ans.push_back(((a*ar[k]*ar[k]) + (b*ar[k]) + c));
                k++;
            } else {
                ans.push_back(((a*ar[l]*ar[l]) + (b*ar[l]) + c));
                l--;
            }
        }
        while (k <= j) ans.push_back((a*ar[k]*ar[k]) + (b*ar[k]) + c), k++;
        while (i <= l) ans.push_back(((a*ar[l]*ar[l]) + (b*ar[l]) + c)), l--;
    }
    return ans;
}
