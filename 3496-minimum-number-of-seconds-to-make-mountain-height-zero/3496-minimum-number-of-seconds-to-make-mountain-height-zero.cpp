#define ll long long
#define p pair<ll,ll>

class Solution {
public:
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        vector<ll>arr(n,0), freq(n,1);
        priority_queue<p,vector<p>,greater<p>>pq;

        for(int i = 0; i < n ; i++) {
            pq.push({workerTimes[i], i});
        }

        while(mountainHeight > 0){
            mountainHeight--;
            ll currVal = pq.top().first;
            ll index = pq.top().second;
            
            arr[index] = currVal;
            // cout<<"{"<<index<<","<< currVal<< "}\n";
            pq.pop();
            freq[index]++;
            pq.push({currVal + (freq[index]*workerTimes[index]), index});

        }

        ll res = 0;
        for(int i = 0; i < n ; i++) {
            res  = max(res, arr[i]);
        }
        return res;
    }

};