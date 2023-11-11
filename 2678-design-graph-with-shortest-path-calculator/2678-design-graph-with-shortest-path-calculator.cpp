class Graph {
public:

    typedef pair<int,int>pair;
    unordered_map<int,vector<pair>> graph;
    int nodes;
    Graph(int n, vector<vector<int>>& edges) {
        for(auto e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }    
        nodes=n;
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair,vector<pair>,greater<pair>>pq;
        pq.push({0,node1});
        vector<bool>isVisited(nodes,false);
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if(p.second == node2)return p.first;
            if(isVisited[p.second])continue;
            
            isVisited[p.second] = true;

            for(auto pairs : graph[p.second]) {
                if(isVisited[pairs.first]) continue;

                pq.push({pairs.second + p.first , pairs.first});
            }

        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */