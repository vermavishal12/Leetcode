class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), cntr = 0;
        queue<int>q;
        bool flip = true;
        for(int i = 0; i <= n-k ; i++) {
            if(!q.empty() && q.front() == i) {
                flip = !flip; 
                q.pop();               
            }
            if(nums[i] ^ flip) {
                cntr++;
                flip = !flip;
                q.push(i+k);
            }
        }

        bool flag = nums[n-k] ^ flip;
        

        for(int i = n- k +1; i < n ; i++) {
            if(!q.empty() && q.front() == i) {
                flip = !flip;
                q.pop();
            }
            if(flag != (nums[i] ^ flip) ){
                return -1;
            }
            
        }
        return cntr;
    }
};