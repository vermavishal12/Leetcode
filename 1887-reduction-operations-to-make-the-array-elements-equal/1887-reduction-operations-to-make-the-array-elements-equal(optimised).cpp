//optimised solution with complexity of time = O(nlogn) and space = O(1)

class Solution {
public:

    int reductionOperations(vector<int>& nums) {
        vector<int>num = nums;
        sort(num.begin(), num.end());

        int val, temp=0,op = 0, n = nums.size()-1;
        while(n && num[0] != num[n]) {
            val = num[n];
            
            while(num[0] != num[n] && val == num[n]) {
                temp++;
                n--;
            }
            op += temp;
        }
        return op;
        
    }

/*
    
*/
};