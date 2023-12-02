/*
    
    1 = taking the element
    for any element we check to pick the element 
    if we pick the element then find the minimum between the answer for the i-1, i-2 and i-3 elements and 
    and then return the answer.
*/

class Solution {
public:
    
    typedef long long ll;
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>arr(n, 0);
        
        arr[0] = max(k-nums[0], 0);
        arr[1] = max(k - nums[1],0);
        arr[2] = max(k - nums[2], 0);
        
        for(int i = 3; i < n ; i++) {
            
            arr[i]= min(arr[i-3], min(arr[i-2], arr[i-1])) + max(k - nums[i] ,0);
            
        }
        
        return min(arr[n-1], min(arr[n-2], arr[n-3]));
        
        
    }
};