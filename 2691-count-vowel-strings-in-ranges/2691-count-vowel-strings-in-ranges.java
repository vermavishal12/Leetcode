class Solution {

    private boolean isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')return true;

        return false;
    }
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length, q = queries.length;
        int[] arr = new int[n+1];

        Arrays.fill(arr, 0);
        int cntr = 0;
        for(int i = 0; i < n ; i++) {
            int N = words[i].length();
            if(isVowel(words[i].charAt(0)) && isVowel(words[i].charAt(N-1))) {
                cntr++;
            }
            arr[i+1] = cntr;
        }
        
        int[] res = new int[q];
        for(int i = 0; i < q ; i++) {
            res[i] = arr[queries[i][1]+1] - arr[queries[i][0]];
        }

        return res;
    }
}