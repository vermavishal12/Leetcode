class Solution {
public:

    
    
    bool canArrange(vector<int>& arr, int k) {
        vector<int>ar(1e5 + 10);
        for(auto &a : arr) {
            
            ar[(a%k + k)%k]++;
        }

        for(int i = 0 ; i <= k/2 ; i++) {
            if(i == 0) {
                if(ar[i]%2)return false;
                continue;
            }
            ar[i] = ar[i];
            ar[k-i] = ar[k-i];

            if(ar[i] != ar[k-i]){
                return false;
            }
        }
        return true;
       
    }
};