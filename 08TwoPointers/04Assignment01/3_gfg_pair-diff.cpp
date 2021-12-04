#include<iostream>
using namespace std; 

bool findPair(int arr[], int size, int n);

int main() {
    int t;
    cin>>t;
    while(t--) {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++) cin>>arr[i];
        if(findPair(arr, l, n)) cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}

bool findPair(int a[], int n, int diff){
    int i = 0, j = 1;
    sort(a, a+n);
    while (j < n) {
        int cur = a[j] - a[i];
        if (cur < diff) j++;
         else if (cur > diff) {
             i++;
             if (i == j) j++;
         } else return true;
    }
    return false;
}
