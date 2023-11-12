class Solution {
public:
    
    typedef long long ll;
    typedef pair<ll,ll> pair;
    unordered_map<int,vector<int>>tree;
    
    pair helper(int node, int parent, vector<int>&values) {
        if(tree[node].size() == 1 && tree[node][0] == parent) {
            return {0,values[node]};
        }
        ll childReqSum = 0,  childTotalSum = 0;
        for(auto child : tree[node]) {
            if(child == parent)continue;
            pair p = helper(child, node, values);
            childReqSum += p.first;
            childTotalSum += p.second;
        }
        
        return {max(childTotalSum , childReqSum + values[node]) , childTotalSum + values[node]};
        
    }
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        
        for(auto edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        pair res = helper(0,-1,values);
        return res.first;
        
    }
};