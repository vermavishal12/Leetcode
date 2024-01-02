class Solution {
public:
    // solve method which will take integer array arr as as input
    int solve(vector<int>&arr) {
        map<int,int>map;
        
        for(auto a: arr){
            map[a]++;
        }
        
        vector<pair<int,int>>ar;
        for(auto m : map) {
            ar.push_back({m.first, m.second});
        }
        int res = -1;
        for(int i = 0 ; i < ar.size() ; i++) {
            if(i > 0) {
                res = max(res, ar[i-1].first);
            }
            if(ar[i].second == 2 && ar[i].first > 2){
                res = max(ar[i].first-1,res);    
            }
            if(ar[i].second > 2)
                res = max(ar[i].first, res);
            if(ar[i].first > 2) 
                res = max(res, ar[i].first-2);
        }
        
        return res;
        
    }
    
    int maximumLength(string s) {
        int n = s.size();
        char prev = s[0];
        vector<vector<int>>arr(26,vector<int>());
        int count = 0;
        for(int i = 0; i < n ; i++) {
            if(prev != s[i]) {
                arr[prev-'a'].push_back(count);
                count  = 0;
            }
            count++;
            prev = s[i];
        }
        
        arr[prev-'a'].push_back(count);
        
        int res = -1;
        // we will find the answer for every cases from a to z amd find the maximum of the answer
        for(int i = 0; i < 26; i++) {
            if(arr[i].size() == 0)continue;
            res = max(res,solve(arr[i]));
            
        }
        
        return res;
        
        
    }
};

