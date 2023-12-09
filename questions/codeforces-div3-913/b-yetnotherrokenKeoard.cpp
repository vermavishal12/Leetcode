#include<bits/stdc++.h>
using namespace std;

string yetnotherrokenKeoard(string s, int n) {
    stack<int>smallCaps, caps;

    for(int i = 0; i < n ; i++) {
        if(s[i] == 'B') {
            if(!caps.empty())
                caps.pop();
        } else if (s[i] == 'b') {
            if(!smallCaps.empty())
                smallCaps.pop();
        } else if(s[i] >= 'a' && s[i] <= 'z') {
            smallCaps.push(i);
        } else if(s[i] >= 'A' && s[i] <= 'Z') {
            caps.push(i);
        }
        
    }
    string res = "";
    while(!caps.empty() && !smallCaps.empty()) {
        if(caps.top() < smallCaps.top()) {
            res += s[smallCaps.top()];
            smallCaps.pop();
        } else {
            res += s[caps.top()];
            caps.pop();
        }
    }

    while(!caps.empty()) {
        res += s[caps.top()];
        caps.pop();
    }
    while(!smallCaps.empty()) {
        res += s[smallCaps.top()];
        smallCaps.pop();
    }

    reverse(res.begin(), res.end());

    return res;

}

void solve(){
    string s;
    cin >>s;
    int n = s.size();
    string res = yetnotherrokenKeoard(s,n);
    cout<<res<<"\n";
    return;
}

int main() {
    int n ; 
    cin >> n;
    while(n--) {
        solve();
    }

    return 0;
}


/*
    ARaBbbitBaby
    
    ity
*/