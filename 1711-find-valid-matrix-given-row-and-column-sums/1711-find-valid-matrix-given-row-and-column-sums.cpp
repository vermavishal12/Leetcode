class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size(); 
        vector<vector<int>>arr(m,vector<int>(n, 0));
        int i=0,j=0;
        while(i < m && j < n) {
            if(rowSum[i] < colSum[j]) {
                arr[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                i++;
            }else if(rowSum[i] > colSum[j]) {
                arr[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                j++;
            }else{
                arr[i][j] = rowSum[i];
                i++;
                j++;
            }
        }
        return arr;
    }
};
