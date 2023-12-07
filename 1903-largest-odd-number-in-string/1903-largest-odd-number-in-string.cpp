class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int size = 0;
        for(int i = 0; i < n ; i++) {
            if((num[i]-'0')%2){
                size = i+1;
            }
        }
        
        return num.substr(0,size);
    }
};