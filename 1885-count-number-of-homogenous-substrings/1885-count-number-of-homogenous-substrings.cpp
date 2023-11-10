class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size() , i=0,mod =1000000007;
        long long ans=0;
        while(i < n){
            int j = i;long long t=0;
            
            while(j < n && s[i] == s[j]){
                t++;
                j++;
            }
            t = (t*(t+1))/2;
            ans = (ans +t)%mod;
            i=j;
        }
        
        return ans%mod;
        
    }
};