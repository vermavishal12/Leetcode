#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int cntr = 0, n = nums.size();
        for(int i = 0; i < n ; i++) {
            if(map[nums[i]] == 0) {
                map[nums[i]] = ++cntr;
            }
        }
        vector<int>res(k+1);
        vector<vector<int>>dp(n+100, vector<int>(k+1,0));
        for(int i = 0; i < n ; i++) {
            for(int j = k ; j >= 0 ; j--) {
                int val = map[nums[i]];
                dp[val][j] = max(dp[val][j] + 1 , (j > 0 ? res[j-1] + 1 : 0));
                res[j] = max(res[j], dp[val][j]);
            }
        }

        return res[k];

    }
};