// absolute difference for the ith element will be like
// absdiff[i] = (i times nums[i] ) - (sum of numbers less than ith element) + (sum of numbers greater than ith element) - (n-i-1 times ith element)
// iterate over each element in the array and calculate the result return the array.

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>absDiff(n,0);
        for(int i = n-2 ; i >= 0; i--) {
            absDiff[i] = nums[i+1] + absDiff[i+1];
        }
        int sum = 0;
        for(int i = 0 ; i < n ; i++ ) {
            
            absDiff[i] = (i)*nums[i] - sum + absDiff[i]- (n-i-1)*nums[i];
            sum += nums[i];
        }
        
        return absDiff;
    
    }
};