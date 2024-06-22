using ll = long long;
class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        int n = power.size(), N = 0;
        vector<ll>arr;
        unordered_map<ll,ll>map;
        for(int i = 0; i < n ;i++) {
            if(map[power[i]] == 0) {
                arr.push_back(power[i]);
            }
            map[power[i]]++;
        }
        sort(arr.begin(), arr.end());
        N = arr.size();
        vector<ll>dp(N+1);
        dp[0] = 0;
        dp[1]= arr[0] * map[arr[0]];
        for(int i = 1; i < N ; i++) {
            ll element = arr[i] * map[arr[i]];
            dp[i+1]= element;
            if(arr[i-1] < arr[i] - 2) {
                dp[i+1] = max(dp[i+1], element + dp[i]);
            } else if(i > 1 && arr[i-2] < arr[i] - 2) {
                dp[i+1] = max(dp[i+1], element + dp[i-1]);
            } else if(i > 2 && arr[i-3] < arr[i] - 2) {
                dp[i+1] = max(dp[i+1], element + dp[i-2]);
            }
            dp[i+1] = max(dp[i], dp[i+1]);
        }

        return dp[N];
        
        
    }
};