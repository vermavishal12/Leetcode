class Solution {
public:
    typedef pair<double, int>p;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    
        vector<vector<p>>graph(n, vector<p>());

        int N = edges.size();

        for(int i = 0; i < N; i++) {
            graph[edges[i][0]].push_back({succProb[i],edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }

        priority_queue<p>pq;
        pq.push({1,start_node});
        vector<bool>visited(n,false);
        while(!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            if(visited[node])
                continue;
            if(node == end_node){
                return prob;
            }
            visited[node] = true;

            for(auto [edgeWt , nbr] : graph[node]) {
                if(visited[nbr])continue;
                pq.push({edgeWt*prob, nbr});
            }
        }

        return 0;
    }
};