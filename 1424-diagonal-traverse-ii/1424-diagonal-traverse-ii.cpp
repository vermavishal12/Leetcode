// in this solution we created a tuple for each element in the 2-D array and then sorted the array on the basis of low to high

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>>t;
        

        for(int i = 0; i < nums.size() ; i++) {
            for(int j = 0; j < nums[i].size() ; j++) {
                t.push_back({i+j,i,nums[i][j]});
            }
        }

        sort(t.begin(), t.end(), [&](vector<int>&a, vector<int>&b) {
            if(a[0] < b[0])return true;
            if(a[0] == b[0]){
                if(a[1] > b[1])return true;
                if(a[1] == b[1])return a[2] < b[2];
            }
            return false;
        });

        vector<int>res;
        for(int i = 0; i < t.size() ; i++){
            res.push_back(t[i][2]);
        }

        return res;
    }
};