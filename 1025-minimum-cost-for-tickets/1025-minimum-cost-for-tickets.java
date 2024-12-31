class Solution {
    
    private void mincostTicketsHelper(int[] arr, int days, int cost, int index){
        for(int i = 0; i < days; i++) {
            if(index + i > 365)break;
            arr[i + index] = Math.min(arr[i + index] , cost);
        }
    }

    public int mincostTickets(int[] days, int[] costs) {
        int[] arr = new int[366];
        Arrays.fill(arr, 1000000);
        int index = 0 , n = days.length;
        arr[0] = 0;
        for(int day = 1 ; day < 366 ; day++) {
            if(index < n && days[index] == day) {
                mincostTicketsHelper(arr, 1, arr[days[index]-1]+costs[0],day);
                mincostTicketsHelper(arr, 7, arr[days[index]-1]+costs[1], day);
                mincostTicketsHelper(arr, 30, arr[days[index]-1]+costs[2], day);
                index++;
            }else {
                arr[day] = Math.min(arr[day], arr[day-1]);
            }
        }
        return arr[days[n-1]];
    }
}