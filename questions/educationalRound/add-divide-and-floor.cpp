#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int m = 0;
void solve() {
    m++;
    int n ;
    
    cin >> n;
    vector<ll>arr(n);
    for(int i = 0 ; i < n ; i++) 
        cin>>arr[i];
    
    sort(arr.begin(), arr.end());
    if(arr[n-1] == arr[0]){
        cout<<"0\n";
        return;
    } 
    
    int ans = log2(arr[n-1]-arr[0]) + 1;
    cout<<ans<<"\n";
    if(ans <= n && ans != 0){
        for(int i= 0 ; i < ans ; i++) {
            cout<<arr[0]<<" ";
        }
        cout<<"\n";
    }
    
    return ;
    
}

/*
100
110
*/
int main() {
    int testCases;
    cin >> testCases;

    while (testCases--){
        solve();
    }

    return 0;
    
}