class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int minA = INT_MAX, minB = INT_MAX, maxA = INT_MIN, maxB = INT_MIN, n = nums.size();
        
        for(int i = 0; i < n ; i++) {
            
            if(minA >= nums[i]) {
                minB = minA;
                minA = nums[i];
            }
            else if(minB >= nums[i]) {
                minB= nums[i];
            }
            
            if(maxA <= nums[i]) {
                maxB = maxA;
                maxA = nums[i];
            } else if(maxB <= nums[i]) {
                maxB = nums[i];
            }
        
                
        }
        // cout<<minA<<" "<<minB;
        // return 0;
        return ((maxB*maxA) - (minA*minB));
    }
};