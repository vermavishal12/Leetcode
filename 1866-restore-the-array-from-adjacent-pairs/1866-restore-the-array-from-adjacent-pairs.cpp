class Solution {
public:

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>map;
        int n = adjacentPairs.size();
        
        for(auto pairs : adjacentPairs) {
            map[pairs[0]].push_back(pairs[1]);
            map[pairs[1]].push_back(pairs[0]);
        }

        unordered_map<int,bool>M;
        vector<int>res;
        
        for(auto m : map) {
            if(m.second.size() == 1) {
                res.push_back(m.first);  
                M[m.first] = true;      
                break;
            }
        }
        int N = 1;
        
        while(N != n+1) {
            for(auto val : map[res[N-1]]) {
                if(!M[val]) {
                    M[val] = true;
                    res.push_back(val);
                    N++;
                }
            }
        }

        return res;
        
        

        return {};

    }
};

