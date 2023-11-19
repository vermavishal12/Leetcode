class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long left = 0, sum =nums[0], res=1;

        
        for(int right = 1; right < n ; right++) {
            while((right-left)*nums[right] - sum > k) {
                sum -= nums[left];
                left++;
            }
            sum += nums[right];
            res = max(res, right-left+1);
        }

        return res;
    }
};