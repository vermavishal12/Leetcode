class Solution {
public:

    void adjustCost(vector<int>&arr, int cost, int index, int days) {
        for(int i = 0 ; i < days ; i++) {
            if(index+i > 365)break;
            arr[i+index] = min(arr[i+index], cost);
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>arr(366,1e6);
        arr[0] = 0;
        int index = 0, n = days.size();
        for(int day = 1; day < 366; day++) {
            
            if(index < n && days[index] == day) {
                adjustCost(arr, arr[days[index]-1]+costs[0], day, 1);
                adjustCost(arr, arr[days[index]-1]+costs[1], day, 7);
                adjustCost(arr, arr[days[index]-1]+costs[2], day, 30);
                index++;
            }else {
                arr[day] = min(arr[day], arr[day-1]);
            }
        }
        
        return arr[days[n-1]];
    }
};