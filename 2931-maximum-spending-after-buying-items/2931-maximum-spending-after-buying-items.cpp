// we created a priority queue and add the last element of every shop
// after adding that into the queue we pop the smallest element of the queue and multiply that with the day
// and add that to the result res and then add the next greater element to the queue from that shop
// return the result

class Solution {
public:
    
    typedef long long ll;
    typedef pair<ll,pair<int,int>>pair;
    
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pair,vector<pair>,greater<pair>>pq;
        int m = values.size(), n = values[0].size();
        
        for(int i = 0 ; i < m ; i++) {
            pq.push({1ll*values[i][n-1] , {i,n-1}});
        }
        
        ll day = 1, res = 0;
        while(!pq.empty()) {
            pair p = pq.top();
            pq.pop();
            res += day*p.first;
            int i = p.second.first;
            int j = p.second.second;
            if(j != 0) {
                pq.push({values[i][j-1] , {i, j-1}});
            }
            day++;
        }
        
        return res;
    }
};