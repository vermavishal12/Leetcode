// from the previous solution we optimised the time complexity
// instead of sorting the array we just iterate the 2-D array in the normal manner
// and stored the element in the array of map corresponding to the (i+j)value where (i,j) is the index
// and then add the element in the array coressponding to each index in the reverse order

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(),maxSum = 0 , size = 0 , index = 0;

        vector<vector<int>>map(100001);     // created the hash table
        for(int i = 0 ; i < m ; i++) {
            size += nums[i].size();         // calculating the size of the resultant array
            for(int j = 0; j < nums[i].size() ; j++) {      
                map[i+j].push_back(nums[i][j]);     // storing the element corresponding to the (i+j) value
                maxSum = max(maxSum, i+j);      
            }
        }

        vector<int>res(size);

        for(int i = 0; i <= maxSum ; i++) {
            for(int j = map[i].size()-1; j>= 0 ; j--) {       // iterating in the reverse order
                res[index++] = map[i][j];
            }
        }
        return res;
        

    }
};