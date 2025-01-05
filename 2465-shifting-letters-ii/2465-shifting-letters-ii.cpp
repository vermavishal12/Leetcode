class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for(auto& shift : shifts) {
            if(shift[2] == 1) {
                dp[shift[0]]++;
                dp[shift[1]+1]--;
            }else {
                dp[shift[0]]--;
                dp[shift[1]+1]++;
            }
        }

        for(int i = 0; i < n ; i++) {
            if(i > 0)dp[i] += dp[i-1];
            int m = (s[i] - 'a' + 26 + (dp[i] + 26)%26)%26;
            s[i] = 'a' + m;
        }

        return s;
    }
};