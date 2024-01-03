class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int res = 0;
        
        vector<int>arr;
        
        for(auto &b : bank) {
            int count = 0;
            for(auto &c : b) {
                if(c == '1') 
                    count++;
                
            }
            if(count)
                arr.push_back(count);
        }
        
        if(arr.size() < 2)return 0;
        
        for(int i = 0; i < arr.size() - 1; i++) {
            res += arr[i]*arr[i+1];
        }
        
        return res;
        
        
        
    }
};