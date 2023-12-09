#include<bits/stdc++.h>
using namespace std;

#define ll long long;

int solve() {
    int n,x;
    cin >> n >> x;

    vector<int>arr(n);

    for(int i = 0; i < n ; i++)
        cin >> arr[i];

    int ans = max(arr[0], 2*(x-arr[n-1]));

    for(int i = 1 ; i < n ; i++) {
        ans = max(ans, arr[i]-arr[i-1]);
    }

    return ans;
}

int main() {
    int testCases;

    cin >> testCases;

    while(testCases) {
        testCases--;
        cout<<solve()<<"\n";
    }

    return 0;
}


/*
   0 1 2 5 7

   0 1 2 5 6

   0 7 10
*/