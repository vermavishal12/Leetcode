class Solution {
public:

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

    void dfs(vector<vector<int>>&g1, vector<vector<int>>&g2, int i, int j, int m, int n, bool& isCount) {
        
        if(i < 0 || j < 0 || i == m || j == n || g2[i][j] == 0)return;
        if(g1[i][j] == 0){
            isCount = false;
        }

        g2[i][j] = 0;
        for(int k = 0; k < 4; k++) {
            dfs(g1,g2,i+dir[k][0],j+dir[k][1],m,n, isCount);
        }
        
        
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int cntr = 0;
        bool isCount;
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n ; j++) {
                if(grid2[i][j] == 1 && grid1[i][j] == 1) {
                    isCount = true;
                    dfs(grid1,grid2,i,j,m,n,isCount);
                    if(isCount)
                        cntr++;
                }
            }
        }
        return cntr;

    }
};