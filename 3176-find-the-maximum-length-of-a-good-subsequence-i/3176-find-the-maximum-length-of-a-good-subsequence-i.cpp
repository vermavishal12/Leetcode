#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>arr(n+1, vector<int>(k+1,0));
        arr[1][0] = 1;
        for(int i = 1; i <= k ; i++) {
            arr[1][i] = 0;
        }

        for(int I = 1; I < n ; I++) {
            arr[I+1][0] = 1;
            for(int J = I-1 ; J >= 0 ; J--) {
                for(int K = 0 ; K <= k ; K++) {
                    if(nums[I] == nums[J]) {
                        arr[I+1][K] = max(arr[I+1][K] , arr[J+1][K]+1);
                    } else {
                        if(K != 0 && arr[J+1][K-1] > 0) {
                            arr[I+1][K] = max(arr[I+1][K] , arr[J+1][K-1]+ 1);
                        }
                    }
                }
            }
        }

        int res = 0;
        for(int j = 1 ; j <= n ; j++) {
            for(int i= 0; i <= k ; i++) {
                res = max(res, arr[j][i]);
            }
        }

        return res;
    }
};