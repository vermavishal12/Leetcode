#include<bits/stdc++.h>

using namespace std;

vector<string> rook(string s) {
    string temp = s;
    vector<string>res;
    for(char c = '1' ; c <= '8' ; c++) {
        temp[1] = c;
        if(temp != s)
            res.push_back(temp);
    }
    temp = s;
    for(char c = 'a' ; c <= 'h' ; c++) {
        temp[0] = c;
        if(temp != s) 
            res.push_back(temp);
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    vector<string> res =  rook(s);
    for(auto c : res) {
        cout<<c<<"\n";
    }
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
//ARaBbbitBaby