class Solution {
    public int maxScore(String s) {
        int n = s.length(), currScore = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s.charAt(i) == '1')currScore++;
        }
        int maxScore = 0;
        for(int j = 0; j < n-1 ; j++) {
            if(s.charAt(j) == '0'){
                currScore++;
            }else {
                currScore--;
            }
            maxScore = Math.max(maxScore, currScore);
        }

        return maxScore;
    }
}