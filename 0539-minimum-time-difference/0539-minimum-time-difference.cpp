class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>arr;

        for(int i = 0; i < timePoints.size(); i++) {
            int hour = (timePoints[i][0]-'0')*10 + (timePoints[i][1]-'0');
            int minutes = (timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');       

            // we will be two values for the time which will help us to find the minimum of the two time difference effectively
            // for ex, for time 00:00 we will be storing the two values => 0 and 24*60 + 0 = 24*60
            // let say we have two other timestamp in the array 00:10 and 23:53 
            // the first entry will help in finding the difference bw 00:10 and 00:00
            // whereas for the timeStamp 23:53 the entry 24*60 will help us to find the minimum difference
            int time = hour*60 + minutes;
            int newTime = time + 24*60;
            arr.push_back(time);
            if(hour < 13)
                arr.push_back(newTime);
        
        }

        sort(arr.begin(), arr.end());
        int ans=INT_MAX;
        for(int i = 0; i < arr.size()-1; i++) {
            ans = min(ans, arr[i+1]-arr[i]);
        }

        return ans;
    }
};