class Solution {
public:
    
    typedef pair<int,int> pair;
    
    bool isPathCrossing(string path) {
        map<pair, bool>map;
        
        map[{0,0}] = true;
        
        pair p = {0,0};
        
        for(char &c : path) {
            if(c == 'N') {
                p.second += 1;
            } else if(c == 'E') {
                p.first += 1; 
            } else if(c == 'W') {
                p.first -= 1;
            } else {
                p.second -= 1;
            }
            if(map[p])return true;
            map[p] = true;
        }
        
        return false;
        
    }
};