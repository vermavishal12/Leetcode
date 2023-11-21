// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// this condition can be transformed to => nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
// and while iterating over every index we check whether nums[j]-rev(nums[j]) exist in the map or not
// and store the value of nums[j] - rev(nums[j]) for every index j in the unordered map


class Solution {
public:

    typedef long ll;
    ll mod = 1e9 + 7;
    ll reverseNumber(int num) {
        ll rev = 0;
        while(num){
            rev = rev*10 + num%10;
            num = num/10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<ll,ll>map;
        ll res = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++) {
            ll val = nums[i];
            ll rev = reverseNumber(nums[i]);
            res += map[val-rev];
            map[val-rev]++;
        }

        return res%mod;


    }
};