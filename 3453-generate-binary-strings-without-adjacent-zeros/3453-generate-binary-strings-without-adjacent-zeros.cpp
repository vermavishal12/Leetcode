class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>res = { "0", "1"};

        for(int i = 2; i <= n ; i++) {
            int m = res.size();
            for(int j = 0 ; j < m ; j++) {
                if(res[j][i-2] != '0'){
                    res.push_back(res[j] + "0");
                }
                res[j] += "1";
            }
        }

        return res;
    }
};