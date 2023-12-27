class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, n = colors.size();
        stack<int>s;
        for(int i = 0; i < n ; i++) {
            
            if(!s.empty() && colors[i] == colors[s.top()]) {
                if(neededTime[s.top()] <= neededTime[i]) {
                    res += neededTime[s.top()];
                    s.pop();
                    s.push(i);
                }else {
                    res += neededTime[i];
                }
            } else {
                s.push(i);
            }
        }
 
        return res;
    
        
    }
};