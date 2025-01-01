class Solution {

    private final int MAX = 2000000000;
    public int minimumFinishTime(int[][] tires, int changeTime, int numLaps) {
        int n = tires.length;
        int[][] arr = new int[n][20];
        for(int i = 0; i < n ; i++) {
            Arrays.fill(arr[i], MAX);
        }
        for(int i = 0; i < n ; i++) {
            arr[i][1] = tires[i][0];

            for(int j = 2; j < 20; j++) {
                if((long) arr[i][j-1] * tires[i][1] >= MAX)break;
                arr[i][j] = arr[i][j-1] * tires[i][1];
            }

            for(int j = 2; j < 20; j++) {
                if((long) arr[i][j-1] * tires[i][1] >= MAX)break;
                arr[i][j] += arr[i][j-1];
            }
        }

        int[] dp = new int[numLaps+1];
        Arrays.fill(dp, MAX);
        for(int i =0 ; i < n; i++) {
            dp[1] = Math.min(dp[1], tires[i][0]);
        }

        for(int i = 2 ; i <= numLaps ; i++) {
            if(i < 20) {
                for(int j = 0; j < n ; j++) {
                    dp[i] = Math.min(dp[i] , arr[j][i]);
                }
            }

            for(int j = i-1 ; j > 0 && j >= i-18 ; j--) {
                dp[i] = Math.min(dp[i], dp[j] + dp[i-j] + changeTime);
            }
            
        }
        return dp[numLaps];
        
    }
}