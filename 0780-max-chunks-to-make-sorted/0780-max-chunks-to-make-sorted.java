// we simply sort the array and check whether the maximum of the element founded till now is equal to  
// the current index then we will increment the partition value.

class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length, res = 0, currMaxElement = -1;
        for(int i = 0; i < n ;i++) {
            int element = arr[i];
            if(currMaxElement < element) {
                currMaxElement = element;
            }

            if(currMaxElement == i) {
                res++;
            }
            
        }
        return res;

    }
}