class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);

        for(auto& w : word) {
            freq[w-'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());
        int curr = 1, cntr = 1;
        int res = 0;
        for(auto &f : freq) {
            if(f == 0)break;
            if(curr == 9){
                curr = 1;
                cntr++;
            }
            res += cntr*f;
            curr++;
        }
        return res;
    }
};