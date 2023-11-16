// the solution is some what similar to the problem Maximum XOR pair with some customizations.
// we will insert the integer into the array in the same way we've done in the maximum xor pair but we also have to remove the elements from the tree.
// consider the pair (nums[i], nums[j]) such that nums[i] > nums[j] so acc to the req abs(nums[i]-nums[j]) <= min(nums[i], nums[j]) which can be modified into nums[i]-nums[j] <= nums[j] ==> nums[i] <= 2*nums[j]
// so will use two iterators left and right such that left <= right and initially left = right = 0. and we will move the iterator left such that condition is always satisfied
// 2*nums[left] >=  nums[right]

class Solution {        
public:
    
    vector<int> tree;       // initializing the vector tree which holds the elements satisfying the condition
    
    string binaryValue(int num) {               // returns the binary representation of the integer num.
        return bitset<32>(num).to_string().substr(11);
    }
    
    
    void insertNum(string s, int index, int n, int pos) {       // inserting the element into the tree.     
        tree[pos]++;
        
        if(index == n)return;
        
        if(s[index] == '0'){
            insertNum(s, index+1, n, pos*2 + 1);
            
        } else {
            insertNum(s, index+1,n , pos*2 + 2);
        }
        
    }
    
    void removeNum(string s, int index, int n, int pos) {       // removing the element in the tree.

        tree[pos]--;
        
        if(index == n)return;
        
        if(s[index] == '0') {
            removeNum(s, index+1, n,1 + pos*2);
        } else {
            removeNum(s, index+1, n, 2*(pos+1));
        }
    }

    string getMaxXor(string s, int index, int n, int pos) {     // getting the maximum xor value from the tree with one of the element as nums[right].
        if(index == n)return "";
        
        // cout<<pos<<" ";
        // val
        if(s[index] == '0') {           // if the current character is '0' will try to get '1' to optimise xor else we will settle with '0'
            if(tree[pos*2 + 2] > 0){
                return "1" + getMaxXor(s, index+1, n, pos*2 + 2);
            } else {
                return "0" + getMaxXor(s, index+1, n , pos*2 + 1);
            }
        } else {
            if(tree[pos*2 + 1] > 0) {       // if the current character is '1' will try to get '0' to optimise xor else we will settle with '1'
                return "1" + getMaxXor(s, index+1, n , pos*2 + 1);
            } else {
                return "0" + getMaxXor(s, index+1, n, pos*2 + 2);
            }
        }
        
    }
    
    int findInteger(string num) {           // returns the integral value of the binary string
        int res= 0;
        for(int i = 0; i < num.size() ; i++) {
            res = res*2 + (num[i] - '0');
        }
        return res;
    }


    int maximumStrongPairXor(vector<int>& nums) {       // flow starts here
        sort(nums.begin(), nums.end());         // first sort the element in the array nums such that for every left < right => nums[left] <= nums[right]
        
        tree.resize(4000000, 0);            // giving the size to the array

        int pos, n = nums.size() , res = 0, left = 0;       // initializing the variables
        int N = 21;
        vector<string>str(n);       // this array stores the binary representation of the every element in the array
        
        for(int i = 0; i < n ; i++) {
            str[i] = binaryValue(nums[i]);  
        }
        
        string s;
        
        for(int right = 0;  right < n ; right++) {   
            while(2*nums[left] < nums[right]) {         // if the nums[right] > 2*nums[left] then move the left pointer forward
                removeNum(str[left], 0,N , 0);
                left++;
            }

            insertNum(str[right], 0, N, 0);     // insert the element in the tree       
            s = getMaxXor(str[right], 0, N , 0);    // then get the maximum xor value
            res = max(res, findInteger(s));     // get the maximum of the current value.
        }
        
        return res;         // returning the result.
    }
};