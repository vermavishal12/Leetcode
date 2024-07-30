class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int curr = 0;
        vector<int>arr(n);
        for(int i = n-2; i >= 0 ; i--) {
            arr[i] = (s[i+1] == 'a') + arr[i+1];
            
        }
        int res = s.size();
        for(int i = 0 ; i < n ; i++) {
            res = min(res, curr + arr[i]);
            if(s[i] == 'b')curr++;
        }

        return res;

        return res;
        
    }
};