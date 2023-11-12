class Solution {
public:

    typedef pair<int,int> pair;

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target)return 0;

        unordered_map<int, set<int>>route;
        unordered_map<int, set<int>>buses;

        int n = routes.size();
        for(int i = 0 ; i < n ; i++) {
            for(auto stops : routes[i]) {
                buses[i].insert(stops);
                route[stops].insert(i);
            }
        }

        
        unordered_map<int,bool>stopVisited;

        unordered_map<int,bool>routeVisited;
        queue<pair>q;
        q.push({0, source}); 
        stopVisited[source] = true;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            for(auto r : route[p.second]) {
                if(routeVisited[r])continue;
                routeVisited[r] = true;
                for(auto stop : buses[r]) {
                    if(stopVisited[stop])continue;
                    if(stop == target)return p.first+1;
                    stopVisited[stop] = true;

                    q.push({p.first+1 , stop});
                }
                buses[r].clear();

                routeVisited[r] = true;
            }
            route[p.second].clear();
        }

        return -1;

    }

};