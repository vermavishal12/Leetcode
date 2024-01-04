class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*
            2 3 3 2 2 4 2 3 4
            2 2 2 2 3 3 3 4 4 
        */
        unordered_map<int,int>map;
        for(auto &num : nums) {
            map[num]++;
        }
        
        int res = 0;
        
        for(auto &m : map) {
            if(m.second == 1)return -1;
            
            res += (m.second/3);
            res += (m.second%3 != 0);
            
        }
        
        return res;
        
    }
};