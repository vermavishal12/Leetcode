class Solution {
public:

    bool isVowel(char c) {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;

        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return true;
        return false;
    }

    string sortVowels(string s) {
        vector<char>vowels;
        int n = s.size();
        for(int i = 0; i < n ; i++) {
            if(isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());
        int j =0;
        for(int i=0; i<n; i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};