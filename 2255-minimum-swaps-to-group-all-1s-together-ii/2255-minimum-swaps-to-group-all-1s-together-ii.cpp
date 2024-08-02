class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int ones = 0, cnt = 0,maxRes= 0;

        for(int i = 0; i < n ; i++)
            ones += nums[i];

        for(int i = 0; i < ones ; i++) {
            cnt += nums[i];
        }   
        maxRes = cnt;
        for(int i = ones ; i < n+ ones ; i++) {
            cnt += nums[i%n] - nums[(i-ones+n) % n];
            maxRes = max(maxRes, cnt);
        }
        return ones - maxRes;

        
    }
};