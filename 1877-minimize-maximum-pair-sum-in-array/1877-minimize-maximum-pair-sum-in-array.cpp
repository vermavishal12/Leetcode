// we simply sort the array and the pair the maximum element in the array with the minimum element in the array
// this way the pair sum is always been minimized

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // sorting the array 

        int n = nums.size();
        int res = 0;
        for(int i = 0 ; i < n/2 ; i++) {
            res = max(res, nums[i]+nums[n-i-1]);    // checking the maximum value of the pair
        }

        return res;
    }
};