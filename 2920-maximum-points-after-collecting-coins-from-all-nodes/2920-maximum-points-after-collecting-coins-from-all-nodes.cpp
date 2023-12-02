/*
    for every node we asscociated a divisdion factor with it such that for every divideFactor value we basically divide the value coins[node] by 2 divideFactor times
    so let's say we are on the node M and the division factor is 2 so we are doing basically coins[node]/4 or coins[node] >> 2

    but one thing that we can inculcate that is if the divideFactor is less than 14 the zero is the value of all coins[node] value beacuse of the fact that coins[node] will always less than 10^4
    hence we will retrun the value 0 if the divideFactor reaches 14 hence optimising out solution (that is because 2^14 > 10^4)

    so we will return create the dp state such that dp[node][divideFactor] will always returns the answer for the subtree with start Node as node and division Factor as divideFactor.

*/

class Solution {
public:
    int K;
    unordered_map<int,vector<int>> tree;
    
    
    int func(int node, int parent, vector<int>&coins, int divideFactor, vector<vector<int>>&arr) {
        if(divideFactor >= 14)return 0;
        
        if(arr[node][divideFactor] != -1)return arr[node][divideFactor];
        
        int case1 =( coins[node] >> divideFactor) - K;
        int case2 = coins[node] >> (divideFactor+1);
        for(auto child : tree[node]){
            if(parent == child)continue;
            
            case1 += func(child,node, coins, divideFactor,dp);
            case2 += func(child, node, coins, divideFactor+1,dp);
        }
        
        return arr[node][divideFactor] = max(case1, case2);
        
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        K=k;
        for(auto edge: edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>>arr(n, vector<int>(14,-1));
        
        return func(0,-1, coins, 0, arr);
    }
};