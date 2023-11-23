// in this solution for each ith query we store the values from nums[l[i]] to nums[r[i]] in the array arr
// then we simply sort the array and check for every consecutive elements in the array there difference must be consistent
// if not so we return false else we return true.

class Solution {
public:

    bool possibleSeq(vector<int>&arr) {
        int d = arr[1] - arr[0];
        for(int i = 1; i < arr.size() ; i++) {
            if(d != arr[i]- arr[i-1])return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool>res(m);
        for(int i = 0; i < m ; i++) {
            vector<int>arr;
            for(int j = l[i] ;j <= r[i] ; j++) {
                arr.push_back(nums[j]);
            }
            sort(arr.begin(), arr.end());
            res[i] = possibleSeq(arr);
        }

        return res;

    }
};