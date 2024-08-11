/* there are only 3 possible ans: 
    (A) 0 (Zero) =>  when the number of islands in the grid are zero or more than one
    (B) 1 (One) => when by making any of the cell which is land as water can divide the island into 2
    (C) 2 (Two) => when the above two cases fails this is the by default answer.
*/

class Solution {
public:

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // recuring call to mark all the cells of the islands
    void countIslands(vector<vector<int>>&grid, int i, int j, int m, int n) {

        for(int k = 0; k < 4 ; k++) {
            int u = i + dir[k][0] , v = j + dir[k][1];

            if(u < 0 || v < 0 || u >= m || v >= n || grid[u][v] != 1)continue;
            grid[u][v] = 0;
            countIslands(grid,u,v,m,n);
        }

        return ;
    }

    // counting the number of islands for the given grid
    int islandCounts(vector<vector<int>>&grid) {
        int m = grid.size(), n = grid[0].size();
        int cntr = 0;

        vector<vector<int>>arr = grid;

        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n ; j++) {
                if(arr[i][j] == 0)continue;
                arr[i][j] = 0;
                cntr++;
                countIslands(arr,i,j,m,n);
            }
        }

        return cntr;
    }

    int minDays(vector<vector<int>>& grid) {
        int cntr = islandCounts(grid);
        if(cntr != 1)return 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n ; j++) {
                if(grid[i][j] == 0)continue;
                grid[i][j] = 0;
                cntr = islandCounts(grid);
                if(cntr != 1)return 1;
                grid[i][j] = 1;
            }
        }

        return 2;


    }
};