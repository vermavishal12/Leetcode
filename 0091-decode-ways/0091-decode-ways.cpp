// LINK to the problem - https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0')return 0;
        vector<int>arr(n+1);
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 1; i < n ; i++) {
            if(s[i] == '0') {
                
                if(s[i-1] != '2' && s[i-1] != '1'){
                    
                    return 0;
                }
                arr[i+1] = arr[i-1];
                
            } else if(s[i] >= '1' && s[i] <= '6') {
            
                if(s[i-1] == '1' || s[i-1] == '2') {
                    
                    arr[i+1] = arr[i-1] + arr[i];
                    
                } else {
                    
                    arr[i+1] = arr[i];
                }
            } else {
                
                arr[i+1] = arr[i];
                if(s[i-1] == '1') {
                    arr[i+1] += arr[i-1];
                }
            }
            
        }
        // cout<<"\n";
        return arr[n];
    }
};