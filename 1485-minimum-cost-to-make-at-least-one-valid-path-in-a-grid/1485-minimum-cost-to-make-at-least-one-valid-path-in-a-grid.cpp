using p = pair<int,pair<int,int>>;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<p, vector<p>, greater<p>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>costArray(m, vector<int>(n,-1));
        int i,j,u,v;
        while(!pq.empty()) {
            int cost = pq.top().first;
            i = pq.top().second.first; j = pq.top().second.second;
            pq.pop();
            if(costArray[i][j] != -1)continue;
            costArray[i][j] = cost;
            for(int k = 0; k < 4 ; k++) {
                u = i + dir[k][0]; v = j + dir[k][1];
                if(u < 0 || v < 0 || u == m || v == n || costArray[u][v] != -1)continue;
                if(grid[i][j] == k+1) {
                    pq.push({cost, {u,v}});
                }else {
                    pq.push({cost+1, {u,v}});
                }
            }
        }

        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n ; j++) {
                cout<<costArray[i][j] <<" ";
            }
            cout<<endl;
        }

        return costArray[m-1][n-1];
    }
};