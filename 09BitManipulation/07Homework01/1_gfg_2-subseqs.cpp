#include<iostream> 
using namespace std; 

class Solution{   
public:
    long long numberOfSubsequences(int n, long long a[]){
        long long int cnt{0};
        for (int i{0}; i<n; i++) if (!(a[i]&(a[i]-1))) cnt++;
        return pow(2, cnt) - 1;
    }
};

int main()  { 
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i) cin >> A[i];
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
}
