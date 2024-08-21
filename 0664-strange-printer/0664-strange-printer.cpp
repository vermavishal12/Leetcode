class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>arr(n, vector<int>(n,1));

        
        for(int l = 2; l <= n ; l++) {
            for(int i = 0; i <= n-l ; i++) {
                int j = i + l - 1;
                
                arr[i][j] = l;
                // loop for checking the optimal split
                for(int k = 0; k < l-1; k++) {
                    int turns = arr[i][i+k] + arr[i+k+1][j];

                    if(s[i+k] == s[j]) {
                        turns--;
                    }

                    arr[i][j] = min(arr[i][j], turns);
                }
            }
        }

        return arr[0][n-1];
    }
};