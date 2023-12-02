class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {  
        vector<int>arr(26);
        int n = chars.size();
        for(int i = 0; i < n ; i++){
            arr[chars[i]-'a']++;
        }
        
        int res =0;
        for(auto word : words){
            vector<int>freq(26,0);
            for(auto w : word) {
                freq[w-'a']++;
            }
            bool flag=  true;
            for(int i = 0; i < 26; i++) {
                if(freq[i] > arr[i]){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                res += word.size();
            }
        }
        
        return res;
            
    }
};