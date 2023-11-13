class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int cnt =0;     // keeping the last element fixed and comparing the result
        for(int i = 0; i < n-1; i++) {
            if(nums1[i] <= nums1[n-1] && nums2[i] <= nums2[n-1])continue;   // if the elements are already less than the last element of the respective array.
            
            if(max(nums1[i],nums2[i]) > max(nums1[n-1] , nums2[n-1]))   // if the maximum of current index element in the arrays is greater than the maximum of the last two values then return -1 as the required condition cannot be satisified.
                return -1;
            
            if(min(nums1[i], nums2[i]) > min(nums1[n-1], nums2[n-1]))   // if the minimum of current index element in the arrays is greater than the minimum of the last two values then return -1 as the required condition cannot be satisified.
                return -1;
            
            cnt++;
            
        }
        
        int temp = 1;   // swapping the last elements of the array and then calculating the result in that case.
        for(int i = 0; i < n-1 ; i++) {
            if(nums1[i] <= nums2[n-1] && nums2[i] <= nums1[n-1])continue;
            
            temp++;
        }
        
        return min(temp, cnt);      // returning the minimum of the result calculated in two scenarios.
        
    }
};