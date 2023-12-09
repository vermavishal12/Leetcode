class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        
        
        
        for(int i = 1; i < n ; i++) {
            int X = abs(points[i][0] - points[i-1][0]), Y = abs(points[i][1] - points[i-1][1]);
            
            res += min(X,Y) + abs(X-Y);
        }
        
        return res;
    }
};