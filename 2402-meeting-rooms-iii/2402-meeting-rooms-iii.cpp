#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long ;
    using p = pair<ll,ll> ;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<ll,vector<ll>, greater<ll>>pq;
        priority_queue<p, vector<p>,greater<p>>PQ;
        for(int i= 0; i < n ; i++) {
            pq.push(i);
        }

        ll cntr = 0, res = 0;
        unordered_map<int,int>freq;
        for(auto M: meetings) {

            while(!PQ.empty() && PQ.top().first <= M[0]){
                pq.push(PQ.top().second);
                PQ.pop();
            }

            if(!pq.empty()) {
                freq[pq.top()]++;
                if(cntr < freq[pq.top()]){
                    cntr = freq[pq.top()];
                    res= pq.top();
                }else if(cntr == freq[pq.top()]){
                    res = min(res, pq.top());
                }
                PQ.push({M[1] ,pq.top()});
                pq.pop();
            }else{
                auto a = PQ.top();
                PQ.pop();
                freq[a.second]++;
                if(cntr < freq[a.second]) {
                    cntr = freq[a.second];
                    res = a.second;
                }else if(cntr == freq[a.second]) {
                    res = min(res, a.second);
                }
                PQ.push({a.first + M[1] - M[0] , a.second});
            }
        }
        return res;

    }
};