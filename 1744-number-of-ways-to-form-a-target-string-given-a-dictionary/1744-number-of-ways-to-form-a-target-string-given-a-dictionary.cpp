class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    int dp[1001][1001];
    ll helper(int i, int k, string& target, int n, int maxLen, vector<vector<int>>&mapList) {
        if(k == n)return 1;
        if(i == maxLen)return 0;
        if(dp[i][k] != -1)return dp[i][k];
        char c = target[k];
        ll res = 0;
        if(mapList[i][c-'a']) {
            ll a = helper(i+1, k+1, target, n, maxLen, mapList)%mod;
            a = (a*mapList[i][c-'a'])%mod;
            res = (res + a) % mod;
        }

        res = (res + helper(i+1, k, target, n, maxLen, mapList)) % mod;
        return dp[i][k] = res;

    }
    int numWays(vector<string>& words, string target) {
        int maxLen = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < words.size() ; i++) {
            if(maxLen < words[i].size()) {
                maxLen = words[i].size();
            }
        }
        vector<vector<int>>arr(maxLen, vector<int>(26, 0));
        for(int i = 0; i < words.size() ; i++) {
            if(maxLen < words[i].size()) {
                maxLen = words[i].size();
            }
            for(int j = 0; j < words[i].size() ; j++) {
                char c = words[i][j];
                arr[j][c-'a']++;
            }
        }


        return helper(0,0,target, target.size(), maxLen, arr);
    }
};