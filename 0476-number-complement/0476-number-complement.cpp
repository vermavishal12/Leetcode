class Solution {
public:
    int findComplement(int num) {
        int res = 0, dec = 0;
        while(num) {
            int bit = num&1;
            if(bit == 0) {
                res += pow(2,dec);
            }
            dec++;
            num = num/2;
        }

        return res;
    }
};