#define ll long long

class Solution {
public:
    ll validSubstringCount(string word1, string word2) {
        
        vector<int>freq(26,0);

        for(char& c : word2) {
            freq[c-'a']++;
        }

        vector<int>cnt(26,0);
        int k = word2.size(), start = 0;
        ll res = 0;
        for(int i = 0; i < word1.size(); i++) {
            
            char curr = word1[i];
            cnt[curr-'a']++;
            
            if(cnt[curr-'a'] <= freq[curr-'a']){
                k--;
            }
        
            while(k == 0) {
                res += word1.size() - i;

                char pre = word1[start];
                cnt[pre-'a']--;

                if(freq[pre-'a'] > 0 && cnt[pre-'a'] < freq[pre-'a']){
                    k++;
                }
                start++;
            }
        }
        return res;
    }
};