class Solution {
public:
    
    string returnSubstring(string s, int low , int high) {
        string res = "";
        for(int i = low; i <= high ; i++){
            res += s[i];
        }
        
        return res;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, bool>map;
        
        for(auto d : dictionary) {
            map[d] = true;
        }
        
        int n = s.size();
        vector<vector<int>>arr(n+1, vector<int>(n+1,100));
        for(int i = 0; i < n ; i++) {
            string temp = "";
            temp += s[i];
            if(map[temp]){
                arr[i][i] = 0;
            }
            else{
                arr[i][i] = 1;
            }
        }
        for(int l = 2; l <= n ; l++){
            for(int i = 0;  i <= n-l ; i++){
                string temp = returnSubstring(s,i,i+l-1);
                if(map[temp]){
                    arr[i][i+l-1] = 0;
                }
                for(int j = i + 1; j < i+l ; j++) {
                    arr[i][i+l-1] = min(arr[i][i+l-1] , arr[i][j-1] + arr[j][i+l-1]);
                }
            }
        }
        
        
        return arr[0][n-1];
        
    }
};