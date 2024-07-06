class Solution {
public:
    int passThePillow(int n, int time) {
        time = time % (2*n - 2);
        
        if(time >= n-1) return 2*n - time - 1;

        return time + 1;

    }
};

// 1 2 3
// 4 3 2
// 1 2 3
// 4 3 2

// 1 2 3 4 5 6 
// 7 6 5 4 3 2
// 1 2 3 4 5 6
// 7 6 5 4 3 2
