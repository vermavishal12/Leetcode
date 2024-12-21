/*
    first we make some node as the root, let say 0 as the root node.
    we simply check if the current subtree has the sum value mod K equals to 0 
    then we simply mark the decision to divide the tree
    else we merge it with its parent
    and we do this iteratively

*/
class Solution {
    int division = 0, K = 0;
    private long maxKDivisibleComponentsHelper(List<Integer>[]adj, int node, int parent , int[]values) {
        long currSum = values[node];

        for(int child: adj[node]) {
            if(child == parent)continue;
            currSum += maxKDivisibleComponentsHelper(adj, child, node, values);
        }

        if(currSum % K == 0){
            division++;
        }
        return currSum%K;
    }
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        List<Integer> [] adjList = new ArrayList[n];
        K = k;
        for(int i = 0; i < n ; i++) {
            adjList[i] = new ArrayList<>();
        } 

        for(int []edge : edges) {
            adjList[edge[0]].add(edge[1]);
            adjList[edge[1]].add(edge[0]);
        }
        long res = maxKDivisibleComponentsHelper(adjList, 0,-1,values);
        return division;


    }
}