class Solution {
public:

    using ll = long long;
    using p = pair<long long , long long>;
    long long continuousSubarrays(vector<int>& nums) {
        ll res = 0;
        int left = 0, n = nums.size();

        map<int,int>frequency;

        for(int right = 0 ; right < n ; right++) {
            frequency[nums[right]]++;

            while(frequency.rbegin()->first - frequency.begin()->first > 2) {
                frequency[nums[left]]--;
                if(frequency[nums[left]] == 0) {
                    frequency.erase(nums[left]);
                }
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};