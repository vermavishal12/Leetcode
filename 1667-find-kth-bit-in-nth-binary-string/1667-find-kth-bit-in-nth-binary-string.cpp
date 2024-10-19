class Solution {
public:
    char findKthBit(int n, int k) {
        // s1 = 0
        // s2 = s1 + "1" + reverse(invert(s1)) => 011
        if(n == 1)return '0';
        int len = (1<<n) - 1;

        int mid = len/2 + 1;
        if(k == mid)return '1';
        if(k < mid) return findKthBit(n-1,k);

        return findKthBit(n-1, len-k+ 1) == '0' ? '1' : '0';
    }
};