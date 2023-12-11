class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = 0;
        int prev = arr[0];
        for(auto &num : arr) {
            if(prev != num){
                freq= 0;
            }
            freq++;
            if(freq > n/4)return num;
            prev= num;
        }
        
        return prev;
    }
};