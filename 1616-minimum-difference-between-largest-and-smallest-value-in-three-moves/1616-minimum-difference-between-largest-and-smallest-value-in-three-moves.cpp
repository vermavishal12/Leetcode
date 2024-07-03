class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 5)return 0;
        
        int n = nums.size();

        
        int res = min(nums[n-1]-nums[3], nums[n-2]-nums[2]);
        res = min(res, nums[n-3] - nums[1]);
        res = min(res, nums[n-4] - nums[0]);
        return res;

    }   
};