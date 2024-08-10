class Solution {
public:

    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    void traverse(int i, int j, vector<vector<int>>& grid, int m, int n) {
        
        for(int k = 0; k < 4; k++) {
            int u = i + dir[k][0], v = j + dir[k][1];
            if(u < 0 || v < 0 || u >= m || v >= n || grid[u][v] != 0)continue;

            grid[u][v] = 1;
            traverse(u,v,grid, m,n);
        }
        return ;
    }

    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cntr = 0;
        
        vector<vector<int>>newGrid(m*3, vector<int>(n*3, 0));

        for(int i = 0;  i< m ; i++) {
            for(int j = 0; j < n ; j++) {
                int row = i*3, col = j*3;

                if(grid[i][j] == '\\'){
                    newGrid[row][col] = 1;
                    newGrid[row+1][col+1] = 1;
                    newGrid[row+2][col+2]= 1;
                }else if(grid[i][j] == '/'){
                    newGrid[row][col+2] = 1;
                    newGrid[row+1][col+1] = 1;
                    newGrid[row+2][col] = 1;
                }
            }
        }

        int M = newGrid.size(), N = newGrid[0].size();
        for(int i = 0; i < M; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(newGrid[i][j] != 0)continue;
                newGrid[i][j] = 1;
                cntr++;
                traverse(i,j,newGrid,M,N);
            }
        }
        return cntr;
    }
};