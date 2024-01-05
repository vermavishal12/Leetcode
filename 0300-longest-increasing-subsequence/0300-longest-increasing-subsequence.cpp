class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n, INT_MAX);
        
        for(int i = 0; i < n ; i++) {
            int k = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            
            arr[k] = min(arr[k], nums[i]);
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] == INT_MAX)return i;
        }
        
        return n;
        
    }
};

