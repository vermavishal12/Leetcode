// find the maximum index for all three types of garbage and add the result variable cnt that many times
// the solutions can be expanded to more than 3 types of garbage easily.

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int p=-1,g=-1,m=-1,n = garbage.size();
        int cnt = 0;
        
        for(int i = 0; i < n ; i++) {
            for(auto c : garbage[i]) {
                if(c== 'P'){
                    p = i;
                } else if(c == 'G') {
                    g = i;
                } else {
                    m = i;
                }
                cnt++;
            }
        }

        for(int i = 0; i < n ; i++) {
            if(i < p){
                cnt += travel[i];
            }
            if(i < m) {
                cnt += travel[i];
            }
            if(i < g) {
                cnt += travel[i];
            }
        }

        return cnt;
    }
};