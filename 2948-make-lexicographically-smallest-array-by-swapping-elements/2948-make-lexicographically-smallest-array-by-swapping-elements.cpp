// first we group the elements in such a way that the every element in a group must be in sorted order and 
// the absolute difference between 2 consecutive elements will always less than the given element
// and then update the nums array such that the sequence of the group in the nums array is always increasing.
/// and return the

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>num;
        int n = nums.size();
        for(int i =0 ;i < n ; i++) {
            num.push_back({nums[i],i});
        }
        sort(num.begin(), num.end());
        set<int>s;
        int i = 0;
        int j = 0;
        while(i < n) {
            set<int>s;
            s.insert(num[i++].second);
            while(i < n && num[i].first - num[i-1].first <= limit){
                s.insert(num[i].second);
                i++;
            }
            for(auto e : s) {
                nums[e] = num[j++].first;    
            }
        }

        return nums;
    }
};