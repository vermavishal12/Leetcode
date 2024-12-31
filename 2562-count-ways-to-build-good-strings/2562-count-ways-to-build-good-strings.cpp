class Solution {
public:
    long mod = 1e9 + 7, res = 0; 
    int zero, one, low, high;
    long dp[1000000];
    long helper(int size) {
        if(size > high)return 0;
        if(dp[size] != -1)return dp[size];
        int res = 0;
        if(size >= low && size <= high)
            res++;

        res += helper(size + zero);
        res += helper(size + one);
        res = res % mod;
        return dp[size] = res;
         
    }

    int countGoodStrings(int l, int h, int z, int o) {
        memset(dp, -1, sizeof(dp));
        low = l; high = h; zero = z; one = o;
        return helper(0);
    }
};