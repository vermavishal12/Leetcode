class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n,1);
        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i-1; j >= 0 ; j--) {
                if(nums[j] < nums[i]) {
                    arr[i] = max(arr[i], arr[j]+1);
                }
            }
            res = max(res, arr[i]);
        }
        
        return res;
        
        
    }
};

