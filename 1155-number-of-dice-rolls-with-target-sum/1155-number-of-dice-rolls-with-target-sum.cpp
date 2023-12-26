class Solution {
public:
    
    typedef long long ll;
    ll mod = 1e9 + 7;
    
    ll func(int n, int k, int target, vector<vector<ll>>&arr) {
        if(arr[n][target] != -1)return arr[n][target];
        
        if(n == 0) { 
            return 0;
        }
        
        ll ans = 0;
        for(int j = 1; j <= k ; j++) {
            if(j > target)break;
            
            ans += func(n-1,k,target-j,arr);
            ans = ans%mod;
        }
        
        return arr[n][target] = ans%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<ll>>arr(n+1,vector<ll>(target+1,-1));
        arr[0][0] =1;
        return func(n,k,target,arr)%mod;
    }
};