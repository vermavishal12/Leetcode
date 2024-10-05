class Solution {
public:

    bool check(vector<int>& freq){
        for(int i = 0; i < 26; i++) {
            if(freq[i]!= 0)return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0);
        int n1 = s1.size(), n2 = s2.size(), left = 0;
        for(auto& c : s1) {
            freq[c-'a']++;
        }
        if(n1 > n2)return false;
        for(int i = 0; i < n1 ; i++) {
            freq[s2[i]-'a']--;
        }
        if(check(freq)){
            return true;
        }

        for(int right = n1; right < n2 ; right++) {
            freq[s2[right]-'a']--;
            freq[s2[left]-'a']++;
            if(check(freq))return true;
            left++;
        }
        return false;

    }
};