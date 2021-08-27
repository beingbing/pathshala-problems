// { Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{

vector<int> getPrimes(const int& n) {
    vector<bool> isPrime(n+1, true);
    isPrime[1] = false;
    int val = sqrt(n);
    for (int i{2}; i <= val; i++)
        if (isPrime[i])
            for (int j{i}; i*j <= n; j++)
                isPrime[i*j] = false;
    vector<int> primes;
    for (int i{1}; i<= n; i++) if (isPrime[i] == 1) primes.push_back(i);
    return primes;
}

public:
    long long primeProduct(long long l, long long r){
        vector<int> primes = getPrimes(sqrt(r));
        vector<bool> isPrime(r-l+1, true);
        for (int i{0}; i < primes.size(); i++) {
            int k = ceil(l*1.0 / primes[i]);
            for (int j{max(k, 2)}; primes[i]*j <= r; j++) {
                isPrime[primes[i]*j - l] = false;
            }
        }
        long long int ans{1};
        long long int mod = 1000000007;
        for (int i{0}; i< isPrime.size(); i++)
            if (isPrime[i] == true) ans = ((ans%mod) * (((i%mod)+(l%mod))%mod))%mod;
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends