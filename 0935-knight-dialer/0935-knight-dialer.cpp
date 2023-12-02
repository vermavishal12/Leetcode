// using dp and find out from which steps we can move to other steps
// for example from 5 we cannot move to any position 
// and from 4 we can move to 3, 9 and 0

class Solution {
public:
    typedef long long ll;
     ll mod  = 1e9 + 7;
    int knightDialer(int n) {
        vector<vector<ll>>t(2,vector<ll>(10,1));

        for(int i = 2; i <= n ; i++) {
            t[1][0] = t[0][4] + t[0][6];
            t[1][1] = t[0][8] + t[0][6];
            t[1][2] = t[0][7] + t[0][9];
            t[1][3] = t[0][4] + t[0][8];
            t[1][4] = t[0][3] + t[0][9] + t[0][0];
            t[1][6] = t[0][1] + t[0][7] + t[0][0];
            t[1][7] = t[0][2] + t[0][6];
            t[1][8] = t[0][1] + t[0][3];
            t[1][9] = t[0][2] + t[0][4];


            for(int i = 0; i <= 9 ; i++) {
                t[0][i] = t[1][i]%mod;
            }
        }
        ll res = 0;
        if(n != 1)res--;
        for(int i =0 ; i <= 9 ;i++) {
            res =(res + t[0][i])%mod;
        }
        
        return res;

    }
};

// 1 -> 8 , 6
// 2 -> 7, 9
// 3 -> 4 , 8
// 4 -> 3, 9, 0
// 5 -> null
// 6 -> 1, 7, 0
// 7 -> 2 , 6
// 8 -> 1, 3
// 9 -> 2, 4
// 0 -> 4, 6
