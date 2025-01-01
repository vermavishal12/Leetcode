using ll = long long;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<vector<ll>>arr(tires.size(), vector<ll>(19, 2e9));

        for(int i = 0; i < tires.size() ; i++) {
            arr[i][1] = tires[i][0];
            for(int j = 2; j < 19 ; j++) {
                if(arr[i][j-1] * tires[i][1] >= 2e9)break;
                arr[i][j] = arr[i][j-1]*tires[i][1];
            }
            for(int j = 2; j < 19 ; j++) {
                if(arr[i][j-1] * tires[i][1] >= 2e9)break;
                arr[i][j] += arr[i][j-1];
            }
        }

        vector<ll>dp(numLaps+1, 2e9);
        for(int i = 1 ; i < tires.size() ; i++) {
            dp[1] = min(dp[1], 1ll*tires[i][0]);
        }

        for(int i = 1; i <= numLaps; i++) {
            if(i < 19){
                for(int j = 0 ; j < tires.size() ; j++) {
                    dp[i] = min(dp[i] , arr[j][i]);
                }
            }
            
            for(int j = i-1; j > 0 && j >= i-18 ; j--) {
                dp[i] = min(dp[i], dp[j] + dp[i-j] + changeTime);
            }
        }
        
        return dp[numLaps];
    }
};

/*
tires[i][0] + changeTime < tires[i][0] * tires[i][1]^(m-1)


using ll = long long;
using p = pair<ll, pair<ll,ll>>;

class Solution {
public:
    
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        priority_queue<p,vector<p>,greater<p>>pq;
        long totalTime = 0 , index = 0;
        long currMin = INT_MAX;
        for(int i = 0; i < tires.size(); i++) {
            if(currMin > tires[i][0]) {
                currMin = tires[i][0];
                index = i;
            }
            else if(currMin == tires[i][0] && tires[index][1] > tires[i][1]) {
                index = i;
            }
            pq.push({changeTime + tires[i][0], {index, 0}});
        }
        numLaps--;
        totalTime = currMin;
        cout<<currMin<<" ";
        pq.push({tires[index][0] * tires[index][1] , {index, 1}});
        while(numLaps--) {
            auto curr = pq.top();
            pq.pop();
            totalTime += curr.first;
            cout<<curr.first<<" ";
            if(index == curr.second.first) {
                long temp = tires[index][0];
                temp = temp * pow(tires[index][1] , curr.second.second + 1);
                pq.push({temp , {index, curr.second.second + 1}});
            } else {
                long temp = tires[index][0];
                temp = temp * pow(tires[index][1], curr.second.second + 1);
                pq.push({temp , {curr.second.first, curr.second.second + 1}});
                index = curr.second.first;
                pq.push({changeTime + tires[index][0], {index, 0}});
            }
        }
        return totalTime;
    }
};
*/