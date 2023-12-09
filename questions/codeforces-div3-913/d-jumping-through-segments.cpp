#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pa;

bool isPossible(int k, vector<pa>&arr, int n) {
    pa p = {0,0};

    for(int i = 0 ; i < n ; i++) {
        p.first = (0,p.first - k);
        p.second += k;

        if(arr[i].second < p.first || arr[i].first > p.second){
            return false;
        }

        p.first = max(p.first, arr[i].first);
        p.second = min(p.second, arr[i].second);

    }
    return true;
}

int jumpingThroughSegments(vector<pa>&arr, int n, int maxValue) {
    int left = 0, right = maxValue;
    int ans = maxValue;
    while(left <= right) {
        int mid = (right - left)/2 + left;
        
        if(isPossible(mid, arr, n)) { 
            ans = mid;
            right = mid-1;

        } else  {
            left = mid+1;
        }

    }
    cout<<"\n";
    return ans;
}

int solve() {
    int n, maxValue = 0; 
    cin >> n;
    vector<pa>arr(n,{0,0});

    for(int i = 0; i < n ; i++) {
        cin >> arr[i].first >> arr[i].second;
        maxValue = max(maxValue, arr[i].second);
    }

    return jumpingThroughSegments(arr,n, maxValue);
}

int main() {
    int n;
    cin >> n;
    vector<int>res(n);
	while(n--) {
        res[n] = solve();
    }

    n = res.size();
    
    for(int i = n-1; i >= 0 ; i--) {
        cout<<res[i]<<"\n";
    }
    
    return 0;

}