class Solution {
public:

    bool calculateHammingDistance(string& a, string& b) {
        int cntr = 0;
        for(int i = 0; i < a.size() ; i++) {
            if(a[i] != b[i]) {
                cntr++;
            }
            if(cntr > 1)return false;
        }
        return cntr == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int>arr(n+1,1), pos(n+1,-1);

        for(int i = 1; i < n ; i++) {
            for(int j = i-1; j >= 0 ; j--) {
                if(groups[i] == groups[j] || words[i].size() != words[j].size())continue;
                if(calculateHammingDistance(words[i], words[j])){
                    if(arr[j] + 1 > arr[i]) {
                        arr[i] = arr[j] + 1;
                        pos[i] = j;
                    }
                }
            }
        }
        int res = 0, currMax = -1;
        for(int i = 0; i < n ;i++) {
            if(res < arr[i]) {
                currMax = i;
                res = arr[i];
            }
        }   

        vector<string>result;
        while(currMax != -1) {
            result.push_back(words[currMax]);
            currMax = pos[currMax];
        }
        reverse(result.begin(), result.end());
        return result;
        
        
    }
};