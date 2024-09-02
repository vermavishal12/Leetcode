#define ll long long

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = accumulate(chalk.begin(), chalk.end(),0ll);
        ll K = k;
        K = K%sum;
        int n = chalk.size();
        
        for(int i = 0; i < n ; i++) {
            if(K < chalk[i]) {
                return i;
            }
            K -= chalk[i];
        }

        return n;
    }
};