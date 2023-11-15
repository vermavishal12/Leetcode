class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int prev = 1, n = arr.size();
        
        for(int i = 1; i < n ; i++) {
            if(prev+1 <= arr[i]) {
                prev++;
            } else {
                prev = arr[i];
            }
        }

        return prev;
    }
};