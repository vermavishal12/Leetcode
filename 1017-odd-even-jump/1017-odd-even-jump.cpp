class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size(), odd = 1, even = 0, cntr = 1;
        
        vector<vector<int>>dp(n, vector<int>(2));
        dp[n-1][odd] = true;
        dp[n-1][even] = true;

        set<int>getJustMaximum;
        set<int, greater<int>>getSmaller;
        getSmaller.insert(arr[n-1]); getJustMaximum.insert(arr[n-1]);
        getSmaller.insert(-1); getJustMaximum.insert(1e6);
        
        unordered_map<int,int>map;
        map[arr[n-1]] = n-1;
    
        for(int i = n-2 ; i >= 0 ; i--) {
            int smaller = *getSmaller.lower_bound(arr[i]);
            int bigger = *getJustMaximum.lower_bound(arr[i]);
            
            if(bigger == 1e6) {
                dp[i][odd] = false;
            } else {
                dp[i][odd] = dp[map[bigger]][even];
            }
            if(smaller == -1) {
                dp[i][even] = false;
            } else {
                dp[i][even] = dp[map[smaller]][odd];
            }
            
            getSmaller.insert(arr[i]);
            getJustMaximum.insert(arr[i]);
            map[arr[i]] = i;

            cntr += dp[i][odd] ? 1 : 0;
            
        }

        return cntr;
        
        
    }
};