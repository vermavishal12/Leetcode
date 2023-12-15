class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>map;
        
        
        for(auto path : paths) {
            map[path[0]]++;
            map[path[1]] += 0;
        }
        
        for(auto city : map) {
            if(city.second == 0)return city.first;
        }
        
        return "";
        
    }
};