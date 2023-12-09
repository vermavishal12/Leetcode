class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int size = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if((num[i]-'0')%2){
                size = i +1;
                break;
            }
        }
        
        return num.substr(0,size);
    }
};