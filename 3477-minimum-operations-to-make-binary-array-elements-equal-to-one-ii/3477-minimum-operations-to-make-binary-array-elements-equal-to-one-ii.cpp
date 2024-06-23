class Solution {
public:


    int minOperations(vector<int>& nums) {
        
        bool curr = true;
        int cnt = 0;
        for(auto& n: nums) {
            if(curr) {
                if(!n) {
                    curr = !curr;
                    cnt++;
                }
            }else { 
                if(n) {
                    curr = !curr;
                    cnt++;
                }
            }
        }

        return cnt;
    }
};