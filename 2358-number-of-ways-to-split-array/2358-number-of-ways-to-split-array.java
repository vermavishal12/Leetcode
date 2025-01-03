class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long suffSum = 0;

        for(int i = n - 1 ; i >= 0 ; i--) {
            suffSum += nums[i];
        }

        long prefSum = 0;
        int cntr = 0;
        for(int i = 0 ; i < n - 1 ; i++) {
            prefSum += nums[i];
            suffSum -= nums[i];
            if(prefSum >= suffSum)cntr++;
        }

        return cntr;
    }
}