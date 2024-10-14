#define v vector<int> 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<v, vector<v>, greater<v>>pq;

        int currMax = INT_MIN;

        for(int i = 0; i < nums.size() ; i++) {
            pq.push({nums[i][0] , i , 0});
            currMax = max(currMax, nums[i][0]);
        }

        vector<int> res = {0,INT_MAX};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currMin = curr[0], listIdx = curr[1], elemIdx = curr[2];

            if(currMax - currMin < res[1] - res[0] || 
                (currMax - currMin == res[1] - res[0] && currMin < res[0])) {
                
                res[0] = currMin; res[1] = currMax;
            }

            if(elemIdx + 1 < nums[listIdx].size()) {
                int nxt = nums[listIdx][elemIdx + 1];
                pq.push({nxt, listIdx, elemIdx + 1});
                currMax = max(currMax, nxt);
            }else{
                break;
            }
        }

        return res;
    }
};