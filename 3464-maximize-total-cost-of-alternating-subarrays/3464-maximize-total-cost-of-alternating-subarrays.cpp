using ll = long long;

class Solution {
public:
    ll maximumTotalCost(vector<int>& nums) {
        ll n = nums.size();
        vector<ll>dp(n+1,0);
        dp[n-1] = nums[n-1];
        for(int i = n-2; i >= 0 ; i--) {
            dp[i] = nums[i] + max(dp[i+1] , dp[i+2] - nums[i+1]);
        }

        return dp[0];

    }
};