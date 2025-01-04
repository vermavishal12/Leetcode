class Solution {
    boolean [][] dp;
    private void countPalindromicSubsequenceHelper(int[] pref, int[] suff, char c) {
        
        for(int i = 0; i < 26; i++) {
            if(pref[i] > 0 && suff[i] > 0)dp[i][c-'a'] = true;
        }
        
    }

    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        int[] suff = new int[26];
        dp = new boolean[26][26];
        for(int i = 0; i < 26; i++) {
            Arrays.fill(dp[i], false);
        }
        Arrays.fill(suff, 0);
        int[] pref = new int[26];
        Arrays.fill(pref, 0);
        for(int i = n-1; i >= 0 ; i--) {
            char c = s.charAt(i);
            suff[c-'a']++;
        }
        int res = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            char c = s.charAt(i);
            suff[c-'a']--;
            countPalindromicSubsequenceHelper(pref, suff, c);
            pref[c-'a']++;
        }

        for(int i = 0; i < 26 ; i++) {
            for(int j = 0 ; j < 26; j++) {
                if(dp[i][j] == true)res++;
            }
        }
        return res;
    }
}