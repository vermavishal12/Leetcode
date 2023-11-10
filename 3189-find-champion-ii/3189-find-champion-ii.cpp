class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int>isPossible(n);       // boolean array to store the number of incoming edeges to the ith node
        for(auto e : edges) {
            isPossible[e[1]]++;
        }
        
        int ans = -1;
        
        for(int i = 0; i < n ; i++) {
            if(isPossible[i] == 0) {        // checking if there is no incoming edges to the node then check there is no more than one nodes of same feature; if so then return -1 else update the ans variable
                if(ans != -1)return -1;
                ans = i;
            }
        }
        
        return ans;
        
        
    }
};