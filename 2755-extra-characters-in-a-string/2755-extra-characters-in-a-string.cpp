class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();

        unordered_map<string,bool>map;

        for(auto& word : dictionary) {
            map[word] = true;
        }

        vector<vector<int>>arr(n+1, vector<int>(n+1, 100));
        string temp = "";
        for(int i = 0; i <n ; i++) {
            temp = "";
            temp += s[i];
            if(map[temp]){
                arr[i][i] = 0;
            }else {
                arr[i][i] = 1;
            }
        }
        for(int len = 2 ; len <= n ; len++) {
            for(int i = 0 ; i <= n-len ; i++) {
                string str = s.substr(i, len);
                if(map[str]) {
                    arr[i][i+len-1] = 0;
                }
                for(int j = i+1 ; j < i+len ; j++) {
                    arr[i][i+len-1] = min(arr[i][i+len-1], arr[i][j-1] + arr[j][i+len-1]);
                }
            }
        }

        return arr[0][n-1];

        // return 

    }
};