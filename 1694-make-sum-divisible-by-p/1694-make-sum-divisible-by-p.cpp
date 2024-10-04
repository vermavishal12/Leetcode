class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long sum = 0;

        for(int i = 0; i < nums.size() ; i++) {
            sum += nums[i];
        }
        if(sum % p == 0)return 0;
        int rem = sum%p, resLen = nums.size();
        long currSum = 0;
        unordered_map<int,int>map;
        map[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            
            int mod = (currSum - rem + p) % p;

            if(map.find(mod) != map.end()) {
                resLen = min(resLen, i - map[mod]);
            }
            map[currSum%p] = i;
        }
        return resLen == nums.size() ? -1 : resLen;
    }
};