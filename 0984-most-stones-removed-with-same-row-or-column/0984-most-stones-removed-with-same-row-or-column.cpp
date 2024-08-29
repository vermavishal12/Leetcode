class Solution {
public:

    // function will do the depth first search
    void dfs(vector<vector<int>>&arr, int node, int parent, vector<bool>&visited) {
        
        for(auto& nbr : arr[node]) {
            if(visited[nbr])continue;
            visited[nbr] = true;
            dfs(arr, nbr, node, visited);
        }
        
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>>arr(n,vector<int>());
        
        // create the graph for the plane such that two points share the edge if they have same x or y coordinate   
        for(int i = 0; i < n ; i++) {
            for(int j = i+1; j < n ; j++) {
                if(stones[i][0] == stones[j][0] || stones[j][1] == stones[i][1]) {
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        int cntr= 0;
        for(int i = 0 ; i < n ; i++) {
            // if the point is already mark visited then we can remove the stone from the plane
            if(visited[i]){
                cntr++;
                continue;

            }
            
            // make the depth first search to all the connected pints in the plane
            dfs(arr,i, -1, visited) ;
        }

        return cntr;
    }
};