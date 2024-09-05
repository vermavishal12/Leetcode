class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        
        int remSum = mean*(n+rolls.size()) - sum;
        
        if(remSum < n || remSum > n*6)return {};
        
        vector<int>arr(n,remSum/n);
        remSum %= n;
        
        for(int i = 0; i < remSum ; i++) {
            arr[i]++;
        }
        return arr;
    }
};