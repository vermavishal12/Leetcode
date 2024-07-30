#define p = pair<int,int>;
class Solution {
public:
    vector<int>adj[10010];

    int func(int step, int time, int change) {
        int ans = 0;
        for(int i  = 0 ; i<  step; i++) {
            int temp = ans/change;
            if(temp&1) {
                ans = (temp+1)*change;
            }
            ans += time;
        }
        return ans;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>arr(n+1);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>>q;
        vector<int>dist1(n+1,INT_MAX), dist2(n+1,INT_MAX);
        dist1[1] = 0;
        q.push({1,0});
        while(!q.empty()) {
            auto node = q.front().first;
            auto dist = q.front().second;
            q.pop();

            for(auto edge : adj[node]) {
                int newDist = dist + 1;
                if(newDist < dist1[edge]) {
                    dist2[edge] = dist1[edge];
                    dist1[edge] = newDist;
                    q.push({edge, newDist});
                }else if( newDist > dist1[edge] && newDist < dist2[edge]) {
                    dist2[edge] = newDist;
                    q.push({edge, newDist});
                }
            }
        }

        int steps = dist2[n];
        if(steps == INT_MAX)return -1;
        return func(steps, time, change);

    }
};