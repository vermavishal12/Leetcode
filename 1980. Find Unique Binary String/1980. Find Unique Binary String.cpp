class Solution {
public:

    int integerRepresentation(string num) {        // function returns the integral value of the string
        int res = 0;
        for(int i =0; i < num.size() ; i++) {
            res = res*2 + (num[i] - '0');
        }
        return res;
    }



    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());     // sorting the nums array 
        int res = 0, n = nums.size();
        for(int i = 0; i < n ; i++) {
            if(res != integerRepresentation(nums[i])){      // checking whether the current value of res is not equal to the binary representation of the current value in the nums
                return bitset<32>(res).to_string().substr(32-n);
            }
            res++;
        }

        return bitset<32>(res).to_string().substr(32-n);    // if not returning the n

    }
};