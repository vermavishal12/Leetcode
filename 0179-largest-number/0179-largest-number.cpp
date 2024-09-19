class Solution {
public:

    string largestNumber(vector<int>& nums) {
        
        vector<string>arr;
        
        for(auto &n : nums){
            arr.push_back(to_string(n));
        }

        // sort the resultant string array such that it is sorted in the ascending order
        sort(arr.begin(), arr.end(),[&](string& a, string& b){
            if(b+a > a+b)return true;
            return false;
        });
        string res = "";

        // iterate in the reverse order to get the maximum resultant integer
        for(int i = arr.size()- 1; i >= 0 ; i--) {
            res += arr[i];
        }
        int i = 0;

        // if there are any extra leading zeros in the resultant then we simply remove all those
        while(i < res.size() && res[i] == '0') {
            i++;
        }
        res = res.substr(i, res.size());
        
        // if the resultant string is empty then we simply return "0"
        if(res == "")return "0";
        return res;
    }
};