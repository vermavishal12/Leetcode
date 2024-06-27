// key note is the constraint that: 
// The given edges represent a valid star graph.

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int>map(n+1,0);

        for(auto& e : edges) {
            map[e[0]]++;
            map[e[1]]++;
            if(map[e[0]]==n-1) return e[0];
            if(map[e[1]] == n-1)return e[1];
        }

        

        return n;
    }
};