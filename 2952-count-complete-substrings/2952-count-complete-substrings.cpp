class Solution {
public:
    
    bool check(vector<vector<int>>&freq, int k, int i, int j) {
        for(int u = 0 ; u < 26; u++) {
            int val = abs(freq[i][u] - freq[j][u]);
            if(val == 0 || val == k)continue;
            return false;
        }
        
        return true;
    }
    
    void update(vector<vector<int>>&freq, char ch, int i) {
        for(int j = 0; j < 26; j++) {
            freq[i][j] = freq[i-1][j];
        }
        
        freq[i][ch-'a']++;
    }
    
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int res =0;
        vector<vector<int>>freq(n+1, vector<int>(26,0));
        
        int last = 0;
        for(int i = 0; i < n ; i++) {
            update(freq, word[i],i+1);
            
            if(i > 0 && abs(word[i]-word[i-1]) > 2){
                last = i;
            }
            
            int N = i+1-k, count = 1;
            
            while(N >= last && count <= 26)  {
                if(check(freq, k, i+1,N)){
                    res++;
                }
                count++;
                N -= k;
            }
        }
        return res;
    }
};
