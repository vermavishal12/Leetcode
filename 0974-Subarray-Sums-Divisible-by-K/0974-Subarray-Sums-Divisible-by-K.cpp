#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<long long,long long>map;
        map[0] = 1;
        int n = nums.size();
        long long sum = 0, res = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum%k;
            mod = mod < 0 ? mod + k : mod; 
            res += map[mod];
            map[mod]++; 
        }

        return res;
    }
};