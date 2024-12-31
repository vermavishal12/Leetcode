class Solution {
    private int low, high, zero, one;
    private long mod = 1000000007;
    long[] dp;

    private long countGoodStringsHelper(int size) {
        if(size > high)return 0;
        if(dp[size] != -1)return dp[size];
        long res = 0;
        if(size >= low && size <= high)res++;

        res += countGoodStringsHelper(size + one);
        res = res % mod;
        res += countGoodStringsHelper(size + zero);
        res = res % mod;
        dp[size] = res;
        return res;
    }
    public int countGoodStrings(int low, int high, int zero, int one) {
        dp = new long[1000000];
        Arrays.fill(dp, -1);
        this.one = one; this.high = high; this.low = low; this.zero = zero;
        return (int) (countGoodStringsHelper(0));
        
    }
}