class Solution {
public:
    
    int totalMoney(int n) {
        int count = 1, res = 0;
        int prev = 0;
        for(int j = 0; j < n ; j++) {
            if(j%7 == 0){
                count = prev + 1;
                prev = count;
            }
            res += count;
            count++;
            
        }
        
        return res;
    }
};