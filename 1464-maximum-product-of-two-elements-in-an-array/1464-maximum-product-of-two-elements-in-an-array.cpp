class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN,  max2 = INT_MIN;
        
        for(auto & num : nums){
            if(num >= max1) {
                max2 = max1;
                max1 = num;
            } else if (num >= max2 && num <= max1) {
                max2 = num;
            }
        }
        
        return (max1-1)*(max2-1);
    }
};