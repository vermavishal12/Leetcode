typedef long long ll;
class Solution {
public:
    ll maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll>arr(n);

        for(auto& r : roads) {
            arr[r[0]]++;
            arr[r[1]]++;
        }

        sort(arr.begin(),arr.end());
        ll res = 0;
        for(ll i = 1 ; i <= n ; i++) {
            res += arr[i-1] * i;
        }
        return res;
    }
};