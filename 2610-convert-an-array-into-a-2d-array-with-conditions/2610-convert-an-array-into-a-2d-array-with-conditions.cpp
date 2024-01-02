class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>map;
        vector<vector<int>>arr;
        for(int &num : nums) {
            if(map[num] == arr.size()) {
                arr.push_back({});
            }
            arr[map[num]].push_back(num);
            map[num]++;
        }
        
        return arr;
    }
};