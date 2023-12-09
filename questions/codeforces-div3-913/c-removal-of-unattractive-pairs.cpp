#include<bits/stdc++.h>

using namespace std;

int removalofUnattractivePairs(string s, int n) {
    vector<int>freq(26,0);
    
    for(int i = 0 ; i < n  ; i++) {
        freq[s[i]-'a']++;
    }
    int res = 0;
    for(int i = 0 ; i < 26 ; i++) {
        res = max(res , 2*freq[i] - n);
    }
    if(n%2 && res == 0)
        res++;
    return res;

}

void solve(){
    int n;
    cin >>n ;
    vector<int>size(n);
    vector<string>str(n);

    for(int i =0;i < n ;i++){
        cin >> size[i] >> str[i];
    }
    
    for(int i = 0; i < n ; i++) {
        int res = removalofUnattractivePairs(str[i], size[i]);
        reverse(str[i].begin(), str[i].end());
        res = min(res, removalofUnattractivePairs(str[i] , size[i]));
        cout<<res<<"\n";
    }
    return;
}

int main(){

    solve();

    return 0;
}

/*

*/