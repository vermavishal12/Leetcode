class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int curr = 0, n = fruits.size(), left = 0, res= 0;

        vector<int>collect(1e5+1,0);
        
        for(int i = 0; i < n ; i++) {
            if(!collect[fruits[i]]) {
                curr++;
            }
            collect[fruits[i]]++;
            while(curr > 2) {
                collect[fruits[left]]--;
                if(collect[fruits[left]] == 0) {
                    curr--;
                }
                left++;
            }

            
            res = max(res, i-left+1);
        }

        return res;
    }
};