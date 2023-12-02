class Solution {
public:
    typedef long long ll;
    int numberOfWays(string corridor) {
        int seats = 0;
        for(int i = 0; i < corridor.size(); i++){
            if(corridor[i] == 'S')
                seats++;
        }
        
        if(seats&1 || seats == 0)return 0;
        

        vector<ll>last;
        int i = 0;
        int n = corridor.size();
        while(i < n){
            int cnt=0;
            while(i < n && cnt < 2){
                if(corridor[i] == 'S')
                    cnt++;
                i++;
            }
            ll temp = 0;
            while(i < n && corridor[i] == 'P'){
                temp++;
                i++;
            }
            last.push_back(temp);
            
        }
        
        last.pop_back();
        ll res= 1;
        ll mod = 1e9 + 7;
        for( i = 0 ;i < last.size() ; i++){
            res = res*(last[i]+1);
            res = res%mod;
        }
        
        return res;
    }
};