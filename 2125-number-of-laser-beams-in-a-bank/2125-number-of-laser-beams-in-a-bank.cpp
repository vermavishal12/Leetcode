class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int res = 0;
        int prev = 0;
        
        vector<int>arr;
        
        for(auto &b : bank) {
            int curr = 0;
            for(auto &c : b) {
                if(c == '1') 
                    curr++;
                
            }
            if(curr) {
                res += prev*curr;
                prev = curr;
            }
        }
        
        
        return res;
        
        
        
    }
};