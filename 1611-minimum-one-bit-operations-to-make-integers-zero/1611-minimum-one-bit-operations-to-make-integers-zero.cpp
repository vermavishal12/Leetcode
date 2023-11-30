class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans =0, k = 0, mask = 1;
        
        
        while(mask <= n) {
            if((n&mask)) {
                ans = (1 << (k+1)) - 1 - ans;
            }
            mask <<=1;
            k++;
        }
        
        return ans;
        
        
    }
};


/*

    11
    2
    
    10 
    11
    01
    00
    
    
    11
    110
    
    can change ith bit in the binary if (i-1)th bit is set to 1 and after (i-2)th to 0th is set to 0
    
    
    _ _ _ _ _ _ _ _ _ _ _ _ _ _       
    0 0 0 0 0 0 1 0 1 1 1 0 1 0
    to change the 0th bit needs = 1
    to change the 1st bit 
    1 1  = 2 
    1 0  = 
    
    if the ith bit in the binary representation is 0 then move forward
    
    if the ith bit in the binary representation is 1 then we have to look for the i-1th bit
        if the bit is 1 then we will check 
        
    1 1 0
    1 0 0 = 3
    
    0 1 0 = 1 + 3 = 4
    
    
    1 0 1 0 1 1 0
    0 = 1
    1 0 = 3
    1 1 0 = 1 + 3 = 4
    0 1 1 0 = 4
    
    1 0 1 1 0
    
     170
     
     to change any of the bit we first check if the ith bit is 1 or not . If so then we just need to add the number of operations to make all the i-2 bits 0
     
     so in order to get the ans we first found for every bit 
*/