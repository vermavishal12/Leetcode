class Object {
    public:
        int number;
        int index;

        Object(int num, int i) {
            number = num;
            index = i;
        }
};

class Solution {
public:
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        Object currMax(0,0);
        vector<Object> suffix(n, currMax) ,prefix(n, currMax);
        int sum = 0;
        for(int i = 0; i < k ; i++) {
            sum += nums[n-i-1];
        }  
        currMax.number = sum;
        currMax.index = n-k;
        suffix[n-k] = currMax;
        for(int i = n-k-1; i >= 0; i--) {
            sum += nums[i] - nums[i+k];
            if(currMax.number <= sum) {
                currMax.number = sum;
                currMax.index = i;
            }
            suffix[i] = currMax;
        }

        sum = 0;
        for(int i = 0 ; i < k ; i++) {
            sum += nums[i];
        }
        currMax.number = sum;
        currMax.index = 0;
        prefix[k-1] = currMax;
        for(int i = k ; i < n ; i++) {
            sum += nums[i] - nums[i-k];
            if(sum > currMax.number) {
                currMax.number = sum;
                currMax.index = i-k+1;
            }
            prefix[i] = currMax;
        }
        sum = 0;

        for(int i = k ; i < k*2; i++) {
            sum += nums[i];
        }

        int res = sum + prefix[k-1].number + suffix[k*2].number;
        vector<int>result = {0, k, suffix[k*2].index};
        
        for(int i = k*2; i < n-k; i++) {
            sum += nums[i] - nums[i-k];
            if(res < sum + prefix[i-k].number + suffix[i+1].number) {
                res = sum + prefix[i-k].number + suffix[i+1].number;
                result = {prefix[i-k].index, i-k+1, suffix[i+1].index};
            }            
        }


        return result;

    }
};