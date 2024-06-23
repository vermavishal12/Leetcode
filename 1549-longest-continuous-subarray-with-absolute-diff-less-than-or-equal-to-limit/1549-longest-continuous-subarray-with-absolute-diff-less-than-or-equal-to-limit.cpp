#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using p = pair<ll,ll>;

class Solution {
public:

    priority_queue<p>maxQueue;
    priority_queue<p,vector<p>,greater<p>>minQueue;

    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size(), left = 0, res = 1;
        for(int right = 0; right < n ; right++) {
            maxQueue.push({nums[right],right});
            minQueue.push({nums[right],right});
            int maxElement = maxQueue.top().first;
            int minElement = minQueue.top().first;

            while(maxElement - minElement > limit) {
                
                while(maxQueue.top().second <= left){
                    maxQueue.pop();
                }
                while(minQueue.top().second <= left) {
                    minQueue.pop();
                }
                maxElement = maxQueue.top().first;
                minElement = minQueue.top().first;
                left++;
            }

            res = max(res, right-left+1);
        }
        return res;
    }
};