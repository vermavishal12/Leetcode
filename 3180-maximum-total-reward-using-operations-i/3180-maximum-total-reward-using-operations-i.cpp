#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();

        int maxValue = rewardValues[n-1];
        vector<vector<bool>>arr(n,vector<bool>(maxValue*4 +1));
        arr[0][0] = true;
        arr[0][rewardValues[0]] = true;
        int res = rewardValues[0];
        for(int i = 1; i < n ; i++) {
            arr[i][0] = true;

            for(int j = 0 ; j <= maxValue*2 ; j++) {
                arr[i][j] = arr[i][j] || arr[i-1][j];
                if(j < rewardValues[i]) {
                    arr[i][j+rewardValues[i]] = arr[i][j+rewardValues[i]] || arr[i-1][j];
                }
                if(arr[i][j] == true){
                    res = max(res,j);
                }
                
            }

        }

        return res;
    }
};