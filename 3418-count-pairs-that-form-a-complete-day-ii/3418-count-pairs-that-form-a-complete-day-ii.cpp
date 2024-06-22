using ll = long long;
class Solution {
public:

    ll countCompleteDayPairs(vector<int>& hours) {
        unordered_map<ll,ll>map;
        ll res = 0;
        int n = hours.size();
        for(int i = 0; i < n ; i++) {
            ll element = hours[i]%24;
            ll reqElement = (24 - element)%24;
            res += map[reqElement];
            
            map[element]++;
        }

        return res;
    }
};