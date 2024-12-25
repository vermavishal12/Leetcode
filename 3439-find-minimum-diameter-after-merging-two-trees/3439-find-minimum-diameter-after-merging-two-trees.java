// we will simply find the diameter of both the trees and the minimum depth that can be possible after merging both the trees. 
// the result will be maximum of depth of both the trees and the median of the diameter of the trees plus one
// this extra one is actually the node that we insert while merging both the trees.

class Solution {
    private int currMax = 0;
    private int traverse(List<List<Integer>>adj, int node, int parent){
        int maxLength = 0;

        for(int child: adj.get(node)) {
            if(child == parent) continue;
            int temp = traverse(adj, child, node) + 1;
            currMax = Math.max(currMax, maxLength + temp);
            maxLength = Math.max(temp, maxLength);
        }

        return maxLength;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int n1 = edges1.length+1, n2 = edges2.length+1;
        List<List<Integer>>e1 = new ArrayList<>(n1);
        List<List<Integer>>e2 = new ArrayList<>(n2);

        for(int i = 0; i < n1 ; i++)e1.add(new ArrayList<>());
        for(int i = 0; i < n2 ; i++)e2.add(new ArrayList<>());

        for(int[] edge: edges1) {
            e1.get(edge[0]).add(edge[1]);
            e1.get(edge[1]).add(edge[0]);
        }

        for(int[] edge: edges2) {
            e2.get(edge[0]).add(edge[1]);
            e2.get(edge[1]).add(edge[0]);
        }

        traverse(e1,0 , -1);
        int maxA = currMax;
        currMax = 0;

        traverse(e2, 0,-1);
        int maxB = currMax;

        return Math.max(Math.max(maxA, maxB), (maxA+1)/2 + (maxB+1)/2  + 1); 

        
    }
}