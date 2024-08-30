typedef pair<int,int>p;
typedef pair<int,pair<int,int>>pp;

const int INF = 2e9 ;

class Solution {
public:

    int dijkstra(vector<vector<p>>&graph, int source, int dest, int n) {
        vector<int>dp(n, INF);

        priority_queue<p, vector<p>, greater<p>>pq;

        dp[source] = 0;
        pq.push({0,source});

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            if(dist > dp[node])continue;

            for(auto e : graph[node]) {
                int wt = e.second, v = e.first;
                if(dist + wt < dp[v]) {
                    dp[v] = dist + wt;
                    pq.push({dp[v], v});
                }
            }
        }

        return dp[dest];

    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<p>>graph(n,vector<p>());

        for(auto e : edges) {
            if(e[2] != -1) {
                graph[e[0]].push_back({e[1], e[2]});
                graph[e[1]].push_back({e[0], e[2]});
            }
            
        }

        int currentDist = dijkstra(graph, source, destination, n);
        if(currentDist < target) return {};
        
        bool tar = (currentDist == target);

        for(auto& e : edges) {
            if(e[2] != -1)continue;

            e[2] = tar ? INF : 1;
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});

            if(!tar) {
                int newDist = dijkstra(graph, source, destination, n);

                if(newDist <= target){
                    tar = true;
                    e[2] += target - newDist;
                }
            }
        }

        return tar ? edges : vector<vector<int>>();

    }
};