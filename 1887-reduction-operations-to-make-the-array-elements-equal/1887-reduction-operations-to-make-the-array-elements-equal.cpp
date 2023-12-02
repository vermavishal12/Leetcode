//this is not the optimized solution but all the test cases are passed on the compiler
class Solution {
public:

    typedef pair<int,int>pair;

    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int>map;

        for(int num : nums) {
            map[num]++;
        }

        vector<pair>arr;
        for(auto m : map) {
            arr.push_back({m.first, m.second});
        }
        sort(arr.begin(), arr.end());
        int n = arr.size() , op = 0;
        while(n > 1) {
            op += arr[n-1].second;
            arr[n-2].second += arr[n-1].second;
            n--;
        }

        return op;
    }
};