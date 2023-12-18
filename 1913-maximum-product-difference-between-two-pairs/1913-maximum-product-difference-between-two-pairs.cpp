class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int minA = INT_MAX, minB = INT_MAX, maxA = INT_MIN, maxB = INT_MIN, n = nums.size();
        
        for(auto &num : nums) {
            if(minA >= num) {
                minB = minA;
                minA = num;
            }
            else if(minB >= num) {
                minB= num;
            }
            
            if(maxA <= num) {
                maxB = maxA;
                maxA = num;
            } else if(maxB <= num) {
                maxB = num;
            }
        
                
        }
        
        return ((maxB*maxA) - (minA*minB));
    }
};