class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        vector<int>arr;

        for(int i = 0; i < n ; i++) {
            if(colors[i] == colors[(i+1)%n]){
                arr.push_back(i);
                
            }
        }

        if(arr.size() == 0)return n;
        if(arr[arr.size() - 1] != n-1){
            arr.push_back(min(arr[0]+ n, n-1+k-1));
        }
            
        int start = 0, res = 0;

        for(int i = 0 ; i < arr.size() ; i++) {
            if(arr[i] - start + 1 < k){
                start = arr[i] + 1;
                continue;
            }

            res += arr[i] - start +2 - k;
            start = arr[i] + 1;
        }
        return res;
    }
};

// 2 - 0 + 1 < 3, res += 2 - 0 + 2 - 3 = 1
// 7 
// arr[i] - k + 1
// arr[i] - k + 1 - start + 1

// 0 1 4
// 0 - 0 + 1 < 4
// start = 3, arr[i] = 8, 
// 8-3+1= 6
// 8-6+1 = 3


