class Solution {
public:
    int dp[110][110][2];

    int findPoints(vector<int>&piles, int alice, int index, int m) {
        if(index >= piles.size())return 0;
        if(dp[index][m][alice] != -1)return dp[index][m][alice]; 
        int res = INT_MAX, stones = 0;
        if(alice){
            res = 0;
        }

        for(int i = 0 ; i < m*2; i++) {
            if(index + i == piles.size())break;
            stones += piles[index + i];
            int left = findPoints(piles, !alice, index+i+1, max(m,i+1));
            if(alice){
                res = max(res, stones + left);
            }else {
                res = min(res, left);
            }
        }

        return dp[index][m][alice] = res;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp,-1, sizeof(dp));

        return findPoints(piles,1,0,1);
    }
};