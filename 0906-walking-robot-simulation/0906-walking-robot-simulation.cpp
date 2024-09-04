#define ll long long
class Solution {
public:

    const int hash = 60001;

    ll coordinates(int x, int y) {
        return x + hash*y;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<ll>obs;

        for(auto& o : obstacles) {
            obs.insert(coordinates(o[0], o[1]));
        }
        // North, East, South, West
        vector<vector<ll>>dir = {{0,1},{-1,0},{0,-1},{1,0}};
        ll currX = 0, currY = 0;
        ll res = 0, currDir = 0;

        for(auto& c : commands) {
            if(c == -1) {
                currDir = (currDir + 3)%4;
            }else if(c == -2) {
                currDir = (currDir + 1)%4;
            }else {
                ll dirX = dir[currDir][0], dirY = dir[currDir][1];
                for(ll i = 0; i < c ; i++) {
                    ll nextX = currX + dirX, nextY = currY + dirY;

                    if(obs.contains(coordinates(nextX,nextY)))
                        break;
                    
                    currX = nextX;
                    currY = nextY;
                }
                res = max(res, currX*currX + currY*currY);
            }
        }

        return res;
    }
};