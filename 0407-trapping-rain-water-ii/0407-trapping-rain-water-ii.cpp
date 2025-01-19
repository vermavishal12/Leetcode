class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<p,vector<p>, greater<p>>pq;
        
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i= 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    pq.push({heightMap[i][j] , {i,j}});
                    vis[i][j] = true;
                }
            }
        }
        int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int height = 0, res = 0;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            int h = node.first;
            int i = node.second.first;
            int j = node.second.second;
            height = max(height , h);
            for(int k = 0 ; k < 4 ; k++){
                int u = i + d[k][0];
                int v = j + d[k][1];
                
                if(u < 0 || v < 0 || u >= m || v >= n || vis[u][v])continue;
                vis[u][v] = true;
                
                res += max(0, height - heightMap[u][v]);
                
                pq.push({heightMap[u][v] , {u,v}});
            
            }
        }
        
        
        return res;
        
        
        
    }
};