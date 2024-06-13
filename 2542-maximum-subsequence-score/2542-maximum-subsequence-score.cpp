#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:

    ll maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<ll>>arr(n,vector<ll>(2)); 

        for(int i = 0; i < n; i++) {
            arr[i][0] = nums2[i];
            arr[i][1] = nums1[i];
        }
        ll res = 0;

        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll sum =0;
        
        sort(arr.begin(), arr.end(), [&](vector<ll>&a, vector<ll>&b) {
            if(a[0] > b[0])return true;
            if(a[0] == b[0])return a[1] > b[1];
            return false;
        });

        for(int i = 0; i < k ; i++) {
            pq.push(arr[i][1]);
            sum += arr[i][1];
        }
        res = max(res, sum*arr[k-1][0]);

        for(int i = k ; i < n ; i++) {
            ll a = pq.top();
            pq.pop();
            res = max(res, (sum - a + arr[i][1])*arr[i][0]);
            pq.push(max(a, arr[i][1]));
            sum += max(a, arr[i][1]) - a;
        }

        return res;
    }
};