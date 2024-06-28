class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<vector<int>>arr(n, vector<int>(2));

        for(int i = 0; i < n ; i++) {
            arr[i][0] = difficulty[i];
            arr[i][1] = profit[i];
        }
        sort(arr.begin(), arr.end());
        int totalProfit = 0, m = worker.size(), j = 0, currProfit = 0;
        sort(worker.begin(), worker.end());
        for(int i = 0; i < m ; i++) {
            while(j < n && arr[j][0] <= worker[i]) {
                currProfit = max(currProfit, arr[j][1]);
                j++;
            }
            totalProfit += currProfit;
        }
        return totalProfit;

    }
};