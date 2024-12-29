class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length, res = 0, currMax = values[n-1] - (n-1);

        for(int i = n-2; i >= 0 ; i--) {
            res = Math.max(res, currMax + values[i] + i);
            currMax = Math.max(currMax, values[i] - i);
        }

        return res;
    }
}