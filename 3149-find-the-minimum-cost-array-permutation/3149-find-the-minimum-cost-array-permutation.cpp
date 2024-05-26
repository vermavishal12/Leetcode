// int N = 15;
int cost[15][15], dp[15][1<<15];
vector<int> arr[15][1<<15];

class Solution {
public:

    bool check(vector<int>&a, vector<int>&b) {
        for(int i =0; i <a.size() ; i++) {
            if(a[i] == b[i])continue;
            else if(a[i] < b[i])return true;
            else
                return false;
        }
        return false;
    }

    int func(int node, int mask, int n) {
        if(mask == ((1<<node)|1)){
            arr[node][mask] = {0,node};
            return cost[0][node];
        }
        if(dp[node][mask] != -1)return dp[node][mask];

        int res = INT_MAX;
        vector<int>A;
        for(int j = 1; j < n ; j++) {
            if((mask&(1<<j)) && j!= node) {
                int ans = func(j,(mask&(~(1<<node))) , n) +cost[j][node];
                if(res > ans) {
                    res = ans;
                    A = arr[j][(mask&(~(1<<node)))];
                }else if(res == ans) {
                    int N = (mask&(~(1<<node)));
                
                    if(!check(A,arr[j][N])){
                        A = arr[j][N];
                    }
                }
            }
        }
        A.push_back(node);
        arr[node][mask] = A;
        return dp[node][mask] = res;
    }

    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i <n ; i++) {
            for(int j = 0; j < n ; j++) {
                if(i == j)continue;
                cost[i][j] = abs(i - nums[j]);
            }
        }

        for(int i= 0 ;i <n ; i++) {
            for(int j = 0; j < (1<<n) ; j++) {
                dp[i][j] = -1;
                arr[i][j] = {};
            }
        }

        int ans = INT_MAX;
        vector<int>res = {};
        int N = ((1<<n)- 1);
        for(int i = 1; i < n ; i++) {
            int c = func(i, N ,n) + cost[i][0];
            if(ans > c) {
                ans = c;
                res = arr[i][N];
            }
            else if(ans == c) {
                if(!check(res,arr[i][N])) {
                    res = arr[i][N];
                }
            }
        }
        
        return res;

    }

};