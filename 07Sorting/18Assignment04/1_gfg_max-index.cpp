#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution{
    public:
        
    int maxIndexDiff(vector<int>& a, int& n)  { 
        vector<pair<int, int>> vec;
        for (int i{0}; i<n; i++) vec.push_back({a[i], i});
        sort(vec.begin(), vec.end());
        int ans{INT_MIN}, mnIdx{INT_MAX};
        for (int i{0}; i<n; i++) {
            mnIdx = min(vec[i].second, mnIdx);
            ans = max(ans, abs(vec[i].second-mnIdx));
        }
        return ans;
    }
};

int main()  {
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        vector<int> arr(num);
        for (int i = 0; i<num; i++) cin>>arr[i];
        Solution ob;
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
    }
    return 0;
}
