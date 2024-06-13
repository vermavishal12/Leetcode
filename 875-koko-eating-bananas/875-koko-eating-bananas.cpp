#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    
    bool check(ll mid, vector<int>&piles, ll h, int n) {
        ll count = 0;
        for(int i = 0; i < n ; i++) {
            count += (piles[i]/mid);
            if(piles[i] % mid) {
                count++;
            }
        }

        if(count <= h)return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        ll n = piles.size();
        ll low = 1, high = piles[n-1] , res = 0;

        while(low <= high) {
            ll mid = low + (high-low)/2;
            if(check(mid, piles,h,n)) {
                high=  mid-1;
                res = mid;
            }else {
                low = mid+1;
            }
        }
        return res;
    }
};