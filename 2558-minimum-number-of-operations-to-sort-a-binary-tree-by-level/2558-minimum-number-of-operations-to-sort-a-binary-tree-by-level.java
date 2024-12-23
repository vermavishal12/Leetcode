/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    //hash map to store the index of the elements on the same level.
    private Map<Integer,Integer> hashMap = new HashMap<>();

    // helper method which will return the number of swaps at each level.
    private int findNumberOfSwaps(List<Integer>levels) {
        List<Integer> sortedArray  = new ArrayList<>(levels);
        Collections.sort(sortedArray);
        int cntr = 0;

        for(int i = 0 ; i < levels.size() ; i++) {
            // if the element at index 'i' in sorted array and non-sorted array are not equal
            // then we need to swap those values
            if(!sortedArray.get(i).equals(levels.get(i))) {
                // will increment the swap counter
                cntr++;
                int a = hashMap.get(sortedArray.get(i));
                int b = hashMap.get(levels.get(i));

                //changing the index in the hash Map
                hashMap.put(sortedArray.get(i),b);
                hashMap.put(levels.get(i), a);

                // swaping the element in the list
                Collections.swap(levels, a, b);
            }
        }
        //will return the swap count at each level
        return cntr;
    }

    public int minimumOperations(TreeNode root) {
        // defining the queue which will help to perfrom the BFS
        Queue<TreeNode> q = new LinkedList<>();

        q.add(root);

        int result = 0;
        while(!q.isEmpty()) {
            int size = q.size();
            // this list will store all the element at particular level
            List<Integer> levels = new ArrayList<>();
            hashMap.clear();

            for(int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                levels.add(node.val);       // adding to the list
                hashMap.put(node.val,i);    // storing the index in hash map

                // putting the left and right node into the queue if they are not null
                if(node.left != null) {     
                    q.add(node.left);
                }
                if(node.right != null) {
                    q.add(node.right);
                }
            }
            result += findNumberOfSwaps(levels);
        }
        return result;
    }
}