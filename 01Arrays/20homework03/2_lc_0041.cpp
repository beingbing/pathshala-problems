#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for (int i{0}; i<n; i++)
            if (a[i] >0 and a[i]<=n) {
                int idx = a[i];
                while (idx > 0 and idx <= n and a[idx-1] != idx) {
                    int temp = a[idx-1];
                    a[idx-1] = idx;
                    idx = temp;
                    
                }
            }
        int i{0};
        for (; i<n; i++) if (a[i] != i+1) return i+1;
        return n+1;
    }
};

int main() {
    vector<int> a = {3,1};
    Solution* obj = new Solution();
    cout << "ans: " << obj->firstMissingPositive(a) << endl;
    return 0;
}