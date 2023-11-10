class Solution {
public:

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>map;        // map to store the adjacency list.
        int n = adjacentPairs.size();
        
        for(auto& pairs : adjacentPairs) {
            map[pairs[0]].push_back(pairs[1]);
            map[pairs[1]].push_back(pairs[0]);
        }

        vector<int>res(n+1);        // resultant array to be returned.
        int curr, prev, i=2;        // curr => current array that we are processing, prev => adjacent of the current element in the resultant array.

        for(auto &m : map) {
            if(m.second.size() == 1) {
                prev = m.first;
                curr = m.second[0];
                break;
            }
        }
        res[0] = prev;
        res[1] = curr;
        while(map[curr].size() != 1) {        // loop to iterate over each element and build the resultant array.
            if(map[curr][0] == prev) {
                res[i] = map[curr][1];
            }
            else{
                res[i] = map[curr][0];
            }
            prev = curr;
            curr = res[i];
            i++;
        }

        res[n] = curr;

        return res;
    }
};
