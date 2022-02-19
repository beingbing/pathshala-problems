#include <iostream>
#include <vector>
using namespace std;

class Solution{

    vector<int> ans;
    
    void move(int disc, int from, int to, int aux, int& stp, int& n) {
        if (disc == 1) {
            stp += 1;
            if (stp == n) ans.push_back(from), ans.push_back(to);
            return;
        }
        move(disc-1, from, aux, to, stp, n);
        stp += 1;
        if (stp == n) ans.push_back(from), ans.push_back(to);
        move(disc-1, aux, to, from, stp, n);
    }
    
public:
    vector<int> shiftPile(int N, int n){
        int stp{0};
        move(N, 1, 3, 2, stp, n);
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin >> N >> n;
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

/*

long long toh(int N, int from, int to, int aux) {
    if(N>0){
        toh(N-1, from, aux, to);
        cout<<"move disk "<< N<<" from rod "<< from<<" to rod "<< to<<endl;
        toh(N-1,aux, to, from);
    }
    return pow(2,N)-1;
}

*/
