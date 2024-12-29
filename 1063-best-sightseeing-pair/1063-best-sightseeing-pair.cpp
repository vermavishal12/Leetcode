class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int res = 0, currMax = values[n-1] - (n-1);

        for(int i = n-2 ; i >= 0 ; i--) {
            res = max(res, currMax + values[i] + i);
            currMax = max(currMax , values[i] - i);
        }
        return res;
    }
};