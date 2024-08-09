class Solution {
public:
    int arr[30];
    bool check (int i, int j, vector<vector<int>>&grid) {

        for(int k = 0; k <= 9 ; k++) {
            arr[k] = 0;
        }

        for(int u = 0; u < 3; u++) {
            for(int v = 0; v < 3 ;v++) {
                arr[grid[u+i][v+j]]++;
            }
        }

        for(int k = 1; k <=9 ; k++){
            if(arr[k] != 1)return false;
        }

        int rowSum1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int rowSum2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int rowSum3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

        int colSum1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int colSum2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int colSum3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

        int diagSum1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int diagSum2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];

        if(rowSum1 == rowSum2 && rowSum1 == rowSum3 && rowSum1 == colSum1 && rowSum1 == colSum2 && 
            rowSum1 == colSum3 && rowSum1 == diagSum1 && rowSum2 == diagSum2){
            return true;
        }

        return false;
        
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cntr = 0;
        for(int i = 0; i <= n-3 ; i++) {
            for(int j = 0; j <= m-3 ; j++) {
                if(check(i,j,grid)){
                    cntr++;
                }
            }
        }

        return cntr;
    }
};