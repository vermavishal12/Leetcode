class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = 0;
        int prev = arr[0];
        for(int i = 0; i < n ; i++) {
            if(prev != arr[i]) {
                freq =0;
            }
            freq++;
            if(freq > n/4)return arr[i];
            prev = arr[i];
        }
        
        return prev;
    }
};