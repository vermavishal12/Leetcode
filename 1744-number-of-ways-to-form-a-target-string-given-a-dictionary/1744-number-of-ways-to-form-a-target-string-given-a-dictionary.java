class Solution {
    private final long MOD = 1_000_000_007;
    private int[][] dp;

    private long numWaysHelper(int i, int k, String target, int n, int maxLen, int[][] mapList) {
        if(k == n)return 1;
        if(i == maxLen)return 0;

        if(dp[i][k] != -1)return dp[i][k];

        char c = target.charAt(k);
        long res = 0;

        if(mapList[i][c-'a'] > 0) {
            long a = numWaysHelper(i+1, k+1, target,n,maxLen,mapList);
            a = (a*mapList[i][c-'a']) % MOD;
            res = (res + a) % MOD;
        }

        res = (res + numWaysHelper(i+1, k, target, n, maxLen, mapList)) % MOD;
        dp[i][k] = (int) res;
        return res;
    }

    public int numWays(String[] words, String target) {
        int maxLen = 0;

        // find the maximum word length
        for(String word : words) {
            maxLen = Math.max(maxLen, word.length());
        }

        int[][] mapList = new int[maxLen][26];

        //filling the frequency array at each index 
        for(String word: words) {
            for(int j = 0; j < word.length(); j++) {
                char c = word.charAt(j);
                mapList[j][c-'a']++;
            }
        }

        int n = target.length();
        dp = new int[maxLen][n];
        for(int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return (int) numWaysHelper(0,0, target, n, maxLen, mapList);
    }
}