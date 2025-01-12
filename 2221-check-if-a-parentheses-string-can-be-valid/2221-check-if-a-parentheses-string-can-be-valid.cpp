class Solution {
public:

    bool helper(string& s, string& locked, char c, int& n) {
        int lockedOpen = 0, unlockedClose = 0;
        for(int i = 0; i < n ; i++) {
            if(locked[i] == '1') {
                if(s[i] == c) {
                    lockedOpen++;
                }else {
                    if(lockedOpen > 0){
                        lockedOpen--;
                    } else if(unlockedClose > 0) {
                        unlockedClose--;
                    } else {
                        return false;
                    }
                }
            } else {
                
                unlockedClose++;
                
            }
        }
        return true;
    }
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n&1)return false;
        string sRev = s;
        string lockedRev = locked;
        reverse(sRev.begin(), sRev.end());
        reverse(lockedRev.begin(), lockedRev.end());
        return helper(s, locked, '(', n) && helper(sRev, lockedRev, ')', n);
    }
};