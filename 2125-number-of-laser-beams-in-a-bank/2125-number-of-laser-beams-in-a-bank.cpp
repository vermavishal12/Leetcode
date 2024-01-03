class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int res = 0, curr = 0, prev = 0;
        
    
        
        for(auto &b : bank) {
            curr = 0;
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