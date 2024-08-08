class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int r = rStart , c = cStart;

        int num = 0, moves = 1, nextMoves = 2, twice = 2;
        int diri = 0, dirj = 1;
        vector<vector<int>>res;
        while(res.size() < rows*cols) {
            if(r >= 0 && r < rows && c >= 0 && c < cols) {
                res.push_back({r,c});
            }

            r += diri;
            c += dirj;
            moves -= 1;

            if(moves == 0) {
                int temp = diri;
                diri = dirj;
                dirj = -temp;
                twice -= 1;
                if(twice == 0) {
                    twice = 2;
                    moves = nextMoves;
                    nextMoves++;
                }else {
                    moves = nextMoves-1;
                }
            }
        }
        return res;

    }
};