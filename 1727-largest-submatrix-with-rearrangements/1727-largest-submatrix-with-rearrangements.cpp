// we basically for each column we count the consecutive number of one's in the array for each (i,j) index in the array
// then for each row we sort each row's value in the descending order and found the maximum rectangle that can be made
// and return the result

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int i = 0; i < m ; i++) {
                if(matrix[i][j] == 0)
                    cnt = -1;
                cnt++;
                matrix[i][j] = cnt;
            }
        }
        int res = 0;
        for(int i = 0; i < m ; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            
            for(int j = 0; j < n ; j++) {
                if(matrix[i][j] == 0)break;
                
                res = max(res, (j+1)*matrix[i][j]);
            }
        }

        return res;

    }
};