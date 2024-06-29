class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n, vector<int>());
        vector<int>inDegree(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }

        queue<int>q;

        for(int i = 0 ; i < n ; i++) {
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>arr;
        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            arr.push_back(currNode);

            for(int& child : g[currNode]) {
                inDegree[child]--;
                if(inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        vector<set<int>>arrSet(n);

        for(auto& node : arr) {
            for(int& child : g[node]) {
                arrSet[child].insert(node);
                arrSet[child].insert(arrSet[node].begin(), arrSet[node].end());
            }
        }

        vector<vector<int>>res(n);
        for(int i = 0; i < n ; i++) {
            for(auto& node : arrSet[i]) {
                res[i].push_back(node);
            }
        }
        return res;

    }
};