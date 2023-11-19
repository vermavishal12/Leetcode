class Solution {
public:
    
    typedef long long ll;
    ll mod = 1e9 + 7;
    ll arr[100001][2][3][2];        // declaring array for memoization
    ll solve(int n, int l, int e, int t) {  
        if(n == 0){
            if(l == 0 && e == 0 && t== 0)return 1ll;        // if atleast 2-e's 1-l and 1-t are done then return 1
            return 0ll;                                     // else return 0 : 0 ways are possible
        }

        if(arr[n][l][e][t] != -1)return arr[n][l][e][t];        // if the state is already visited then returned the stored value
        ll res = (solve(n-1,l,e,t)*23)%mod;                     // else calculating the state value : case 1 = taking all the elements except l,e and t
        res += (solve(n-1,max(0,l-1),e,t))%mod;                 // calculating the value with placing 'l' at the index n
        res += (solve(n-1,l,max(0,e-1),t))%mod;                 // calculating the value with placing 'e' at the index n
        res += (solve(n-1,l,e,max(0,t-1)))%mod;                 // calculating the value with placing 't' at the index n

        return arr[n][l][e][t] = res%mod;           // returning the value after storing in the array
    }

    int stringCount(int n) {        
        if(n < 4)return 0;          // if the length of string is less than 4 then there is no string with substring 'leet' hence return 0

        for(int i =0;i<=n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<2;l++)
                        arr[i][j][k][l]=-1;
                }
            }
        }
        
        return solve(n,1,2,1)%mod;      
    }
};


/*

    n = 4
    l e e t
    
    (e) l e t  => 6
    (l) e e t  => 3
    (t) e e l  => 3
     
*/