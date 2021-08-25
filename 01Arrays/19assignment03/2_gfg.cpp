// Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’ 
#include <iostream>
#include <vector>
using namespace std;

// limitation: this will not work if array contains multiple cycles
void rearrangeM1(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n, 0);
    for (int i{0}; i<n; i++) temp[arr[i]] = i;
    for (int i{0}; i<n; i++) arr[i] = temp[i];
}

// limitations: it still uses a lot of vars and loops
void rearrangeM2(vector<int>& a) {
    int n = a.size();
    for (int i{0}; i<n; i++) {
        if (a[i] >= 0) {
            int idx = a[i], nwVal = i;
            while (idx != i) {
                int temp = a[idx];
                a[idx] = -1*(nwVal+1);
                nwVal = idx;
                idx = temp;
            }
            a[idx] = -1*(nwVal+1);
        }
    }
    for (int i{0}; i<n; i++) a[i] = -1*a[i] - 1;
}

// limitations: if numbers are too big then overflow can occur
// (n * new_val) + old_val
void rearrangeM3(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int oldVal = a[i]%n;
        a[oldVal] = a[oldVal] + n*i;
        // a[a[i] % n] += i * n;
    }
// divide with n, old_val will be discarded and new_val is what you get
    for (int i = 0; i < n; i++) a[i] /= n;
}

int main() {
    vector<int> arr = {2,0,1,4,5,3};
    rearrangeM3(arr);
    for (auto ele : arr) cout << ele << '\t';
    cout << endl;
    return 0;
}