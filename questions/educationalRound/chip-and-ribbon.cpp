#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve() {
    int n;
    cin >> n;

    vector<ll>arr(n+1);

    for(int i =0; i< n ; i++)   
        cin >> arr[i+1];

    ll res =0 ;
    arr[0] = 1;
    for(int i = 0; i < n ; i++) {
        res += max(0ll, arr[i+1]-arr[i]);
    }

    return res;
}

int main() {
    int testCases;
    cin >> testCases;

    while(testCases--) {
        cout<<solve()<<"\n";
    }

    return 0;
}


/*

4
4
1 2 2 1
5
1 0 1 0 1
5
5 4 3 2 1
1
12

    1 2 2 1
    _ _ _ _

 */