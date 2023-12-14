class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();    // size of the array
        
        int left = 0, ans =0;
        unordered_map<int,int>freq;     // created the frequency table for each integer
        for(int right = 0 ; right < n ; right++) {
            freq[nums[right]]++;        // we increment the frequency of the element in the iteration
            
            while(freq[nums[right]] > k)    // if the frequency is greater than k then we will move the left pointer and decrement the frequency
                freq[nums[left++]]--;
            
            ans = max(ans, right-left+1);       // checking the maximum value that we can get
        }
                
        return ans;         // returning the answer
    }
};